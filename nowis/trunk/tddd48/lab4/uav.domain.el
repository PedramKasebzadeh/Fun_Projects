#standardtime
#concurrent
#redundancycheck 0


// TALplanner uses explicitly defined types.  In the problem domain,
// we define domains and their hierarchical relation ships.  We can
// also define elements (object constants) that are available in all
// problem instances, but this isn't used in this domain.  Instead we
// define all elements in the problem instance.  The boolean domain,
// with the elements true and false, is automatically declared.

#domain type-or-thing :elements {}
#domain thing :parent type-or-thing :elements {}

#domain uav :parent thing :elements {}
#domain largeuav :parent uav :elements {}
#domain carrier :parent thing :elements {}
#domain location :elements {}
#domain depot :parent location :elements {}
#domain type :parent type-or-thing :elements {}

// We use a domain of integers from 0 to 9999.
#domain smallint :fixedpoint :lb 0 :ub 10000 :decimals 0

// TALplanner uses a state variable representation, though for
// historical reasons state variables are called "features".

#feature at(thing, location) :domain boolean

#feature empty(uav) :domain boolean
#feature holding(uav, type-or-thing) :domain boolean

// The following features are declared as resources.  TALplanner then
// provides the necessary machinery for keeping track of how units of
// these resources are produced and consumed concurrently from many
// actions at the same time.

#resource need(type, location) :domain smallint :preference :less
#resource totalneed(location) :domain smallint :preference :less
#resource supply(type, location) :domain smallint :preference :more

#resource carrierhas(carrier, type) :domain smallint :preference :none
#resource carrierspace(carrier) :domain smallint :preference :none

// TALplanner supports concurrency.  Therefore we need a way of
// ensuring that the planner only places two actions in parallel if
// they would in fact be executable in parallel in reality.  In
// TALplanner we do this by using resources as mutexes.

#resource lock(thing) :domain smallint :preference :less

// At the start, every lock is 1 (available).  We always have 0 or 1
// units, corresponding to the states of being used and available.  In
// the operators, you can see that certain locks are "borrowed" for
// the entire duration of an action, meaning that the resource is
// taken at the beginning of the action and automatically returned
// when the action ends.

#dom [0] forall thing [ $init(lock(thing)) == 1 ]
#dom [0] forall thing [ $minimum(lock(thing)) == 0 ]
#dom [0] forall thing [ $maximum(lock(thing)) == 1 ]

// We define some variables to be used below.  Also, domain names can
// automatically be used as variables.  In other words, "uav" is a
// variable of type uav.

#valuevar from, to :domain location
#timevar start, dur, end

#deffeature totalsupply(location) :domain smallint
#deffeature totalon(carrier) :domain smallint

#define [t] totalsupply(location): value(t, $sum(<type>, true, supply(type, location)))
#define [t] totalon(carrier): value(t, $sum(<type>, true, carrierhas(carrier, type)))


#operator fly-to(uav, from, to)
  :at start, end
  :duration 100 :as dur
  :agent uav
  :precond [start] at(uav, from)
  :control :name "don't-fly-away-with-needed-supplies"
	[start] !exists type [ holding(uav, type) & need(type, from) > 0 ]
  :control :name "don't-fly-away-with-carrier-containing-needed-supplies"
  [start] !exists carrier [ holding(uav, carrier) & 
                            exists type [ (carrierhas(carrier, type) > 0) &
                                          (need(type, from) > 0) ] 
                          ]
  :control :name "don't-fly-to-location-that-don't-need-supplies"
  [start] exists depot [ to = depot ] |
          !exists carrier [ holding(uav, carrier) &
                            exists type [ (carrierhas(carrier, type) > 0) &
                                          (need(type, to) == 0) ] 
                          ]
  :control :name "don't-move-empty-carrier-if-at-depot"
  [start] !exists depot [ from = depot ] |
          !exists carrier [ holding(uav, carrier) & totalon(carrier) == 0 ]
  :control :name "don't-fly-to-same-location"
  [start] !(from = to)
  :control :name "don't-move-empty-from-depot"
  [start] !exists depot [ from = depot ] |
          exists type-or-thing [ holding(uav, type-or-thing) ]
  :control :name "don't-direct-delivry-unless-only-1-crate-is-needed"
  [start] exists carrier [ holding(uav, carrier) ] | 
          exists type [ holding(uav, type) & need(type, to) == 1 ]
  :control :name "don't-fly-away-with-not-full-carrier"
  [start] !exists depot [ from = depot ] |
          !(exists carrier [ holding(uav, carrier) ]) |
          exists carrier [ holding(uav, carrier) &
                            (totalon(carrier) == totalneed(to) |
                             carrierspace(carrier) == 0
                            )
                         ]
  :control :name "if-not-at-depot-fly-only-to-depot"
  [start] exists depot [ from = depot | to = depot ]
  :control :name "don't-fly-with-carrier-to-location-where-need-<-2-supplies"
  [start] exists depot [ to = depot ] | 
          !exists carrier [ holding(uav, carrier) ] | totalneed(to) > 1
  
  :resources
	[+1,+dur] :borrow lock(uav) :amount 1
  :effects
	[+dur - 1] at(uav, from) := true,
	[+dur] at(uav, from) := false,
	[+dur] at(uav, to) := true

#operator pick-up-carrier(largeuav, carrier, location)
  :at start, end
  :duration 5 :as dur
  :agent largeuav
  :precond [start] at(largeuav, location) & at(carrier, location) & empty(largeuav)
  :control :name "don't-pick-up-empty-carrier-at-depot"
  [start] !(totalon(carrier) == 0 & exists depot [ at(carrier, depot) ])
  :control :name "don't-pick-up-carrier-while-unloading"
  [start] !exists type [ carrierhas(carrier, type) > 0 & 
                         (need(type, location) > 0) 
                       ]
                       
  :resources
	[+1,+dur] :borrow lock(largeuav) :amount 1,
	[+1,+dur] :borrow lock(carrier) :amount 1
  :effects
	[+dur] at(carrier, location) := false,
	[+dur] empty(largeuav) := false,
	[+dur] holding(largeuav, carrier) := true

#operator put-down-carrier(largeuav, carrier, location)
  :at start, end
  :duration 1 :as dur
  :agent largeuav
  :precond [start] at(largeuav, location) & holding(largeuav, carrier)
  :control :name "don't-put-down-full-carrier-at-dummy-loc"
  [start] !((totalon(carrier) > 0) & ((totalneed(location) == 0) |
                                      exists depot [ at(largeuav, depot) ]
                                     )
           )
  :control :name "don't-put-down-carrier-at-dummy-loc"
  [start] !exists type [ carrierhas(carrier, type) > 0 & 
                         (need(type, location) <= 0) 
                       ]
  :control :name "put-down-empty-carrier-only-at-depot"
  [start] !(totalon(carrier) == 0) | exists depot [ location = depot ]

  :resources
	[+1,+dur] :borrow lock(largeuav) :amount 1,
	[+1,+dur] :borrow lock(carrier) :amount 1
  :effects
	[+dur] at(carrier, location) := true,
	[+dur] empty(largeuav) := true,
	[+dur] holding(largeuav, carrier) := false

#operator pick-up-crate(uav, type, depot)
  :at start, end
  :duration 2 :as dur
  :agent uav
  :precond [start] at(uav, depot) & empty(uav)

  :resources
	[+dur] :consume supply(type, depot) :amount 1,
	[+1,+dur] :borrow lock(uav) :amount 1
  :effects
	[+dur] empty(uav) := false,
	[+dur] holding(uav, type) := true

#operator put-down-crate(uav, type, location)
  :at start, end
  :duration 2 :as dur
  :agent uav
  :precond [start] at(uav, location) & holding(uav, type)
  :control :name "don't-put-down-at-depot"
  [start] !exists depot [ at(uav, depot) ]

  :resources
	[+dur] :consume need(type, location) :amount 1,
	[+dur] :consume totalneed(location) :amount 1,
	[+1,+dur] :borrow lock(uav) :amount 1
  :effects
	[+dur] empty(uav) := true,
	[+dur] holding(uav, type) := false

#operator load-carrier(uav, depot, type, carrier)
  :at start, end
  :duration 3 :as dur
  :agent uav
  :precond [start] holding(uav, type) & at(uav, depot) & at(carrier, depot) &
                   carrierspace(carrier) > 0
  :control :name "don't-load-with-same-type"
  [start] carrierhas(carrier, type) == 0 | 
          !exists type type2 [ carrierhas(carrier, type2) == 0 ]

  :resources
	[+dur] :consume carrierspace(carrier) :amount 1,
	[+dur] :produce carrierhas(carrier, type) :amount 1,
	[+1,+dur] :borrow lock(uav) :amount 1
  :effects
	[+dur] holding(uav, type) := false,
	[+dur] empty(uav) := true

#operator unload-carrier(uav, location, type, carrier)
  :at start, end
  :duration 3 :as dur
  :agent uav
  :precond [start] empty(uav) & at(uav, location) & at(carrier, location) &
                   carrierhas(carrier, type) > 0
  :control :name "don't-unload-at-depot"
  [start] !exists depot [ location = depot ]
  :control :name "don't-unload-uneeded-ressource"
  [start] need(type, location) !== 0 
  
  :resources
	[+dur] :produce carrierspace(carrier) :amount 1,
	[+dur] :consume carrierhas(carrier, type) :amount 1 ,
	[+1,+dur] :borrow lock(uav) :amount 1
 :effects
	[+dur] holding(uav, type) := true,
	[+dur] empty(uav) := false
