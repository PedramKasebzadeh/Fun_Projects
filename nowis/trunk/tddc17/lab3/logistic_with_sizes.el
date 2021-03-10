;; This is a plain STRIPS formulation of the standard Logistics domain.

;; In this domain, there are six different types of objects: "object"
;; (the packages to be transported), "truck", "airplane" and their
;; common supertype "vehicle", "location" and the subtype "airport",
;; and finally "city". Types are defined by static (in the sense that
;; there are no operators that change their truth value) unary predicates.
;; The types of objects in a problem instance must be defined by including
;; the appropriate typing predicates in the initial state.

;; A binary static predicate called "loc" describes the topology of the
;; problem instance: "(loc ?l ?c)" is true iff the location ?l is in city
;; ?c.

(define (domain logistics)
  (:requirements :strips)
  (:predicates

   ;; Static predicates:
   (object ?o) (truck ?t) (airplane ?p) (train ?t) (vehicle ?v)
   (location ?l) (airport ?a) (trainStation ?s) (city ?c) (loc ?l ?c)
   (small_s ?s) (big_s ?s) ;; objects sizes

   ;; Non-static predicates:
   (at ?x ?l) ;; ?x (package or vehicle) is at location ?l
   (in ?p ?v) ;; package ?p is in vehicle ?v
  )

  ;; Actions for loading and unloading packages.
  ;; By declaring all trucks and train and airplanes to be also "vehicle", we
  ;; can use the same load/unload operator for both (otherwise we
  ;; would need one for each subtype of vehicle).
  (:action load
    :parameters (?o ?v ?l)
    :precondition (and (object ?o) (vehicle ?v) (location ?l)
		               (at ?v ?l) (at ?o ?l)
                   (or (and (truck ?v) 
                            (or (and (big_s ?o)
                                 (not (exists (?x) (and (in ?v ?x) (big_s ?x))))
                                )     
                                (and (small_s ?o)
                                 (not (exists (?x ?y) (and (in ?v ?x) (in ?v ?y)
                                                           (small_s ?x) 
                                                           (small_s ?y)
                                                      )
                                 ))
                                )
                            )
                       )
                       (train ?v)
                       (airplane ?v)
                   )
                  )
    :effect (and (in ?o ?v) (not (at ?o ?l)))
  )

  (:action unload
    :parameters (?o ?v ?l)
    :precondition (and (object ?o) (vehicle ?v) (location ?l)
		       (at ?v ?l) (in ?o ?v))
    :effect (and (at ?o ?l) (not (in ?o ?v)))
  )

  ;; Drive a truck between two locations in the same city.
  ;; By declaring all locations, including airports, to be of type
  ;; "location", we can use only one driving operator (otherwise,
  ;; we would again need one for each case, i.e. one for from-location-
  ;; to-airport, one for from-location-to-location, etc. Very
  ;; unnecessay).
  (:action drive
    :parameters (?t ?l1 ?l2 ?c)
    :precondition (and (truck ?t) (location ?l1) (location ?l2) (city ?c)
		       (at ?t ?l1) (loc ?l1 ?c) (loc ?l2 ?c))
    :effect (and (at ?t ?l2) (not (at ?t ?l1)))
  )

  ;; Move a train between 2 train stations.
  (:action ride
    :parameters (?t ?s1 ?s2)
    :precondition (and (train ?t) (trainStation ?s1) (trainStation ?s2)
		       (at ?t ?s1))
    :effect (and (at ?t ?s2) (not (at ?t ?s1)))
  )
  
  ;; Fly an airplane between two airports.
  (:action fly
    :parameters (?p ?a1 ?a2)
    :precondition (and (airplane ?p) (airport ?a1) (airport ?a2)
		       (at ?p ?a1))
    :effect (and (at ?p ?a2) (not (at ?p ?a1)))
  )
)
