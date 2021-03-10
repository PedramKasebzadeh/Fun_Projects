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
   (driving ?t) ;; truck ?t is driving between 2 cities
   (step1 ?t) (step2 ?t) (step3 ?t) (step4 ?t) (step5 ?t) (step6 ?t) (step7 ?t)
   (step8 ?t) (step9 ?t) (step10 ?t) (step11 ?t) (step12 ?t)   
  )

  ;; Actions for loading and unloading packages.
  ;; By declaring all trucks and train and airplanes to be also "vehicle", we
  ;; can use the same load/unload operator for both (otherwise we
  ;; would need one for each subtype of vehicle).
  (:action load
    :parameters (?o ?v ?l)
    :precondition (and (object ?o) (location ?l)
		               (at ?v ?l) (at ?o ?l)
                   (or (and (truck ?v) (not (driving ?v)) 
                            (or (not (exists (?x) (and (in ?v ?x) (big_s ?x))))
                                (and (small_s ?o)
                                 (not (exists (?x ?y) (and (in ?x ?v) (in ?y ?v)
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
    :precondition (and (object ?o) (location ?l)
                       (or (and (truck ?v) (not (driving ?v)))
                           (train ?v)
                           (airplane ?v)
                       )
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
            		       (at ?t ?l1) (loc ?l1 ?c) (loc ?l2 ?c)
                       (not (driving ?t))
                  )
    :effect (and (at ?t ?l2) (not (at ?t ?l1)))
  )

  ;; Drive a truck between 2 cities (from l1 to l2)
  (:action drive_between_cities
    :parameters (?t ?l1 ?l2)
    :precondition (and (truck ?t) (location ?l1) (location ?l2) 
                       (not (driving ?t))
            		       (at ?t ?l1)
                       (forall (?c) (not (and (loc ?l1 ?c) (loc ?l2 ?c))))
                  )
    :effect (and (at ?t ?l2) (not (at ?t ?l1)) (driving ?t) (step1 ?t))
  )

  ;; Drive a truck between 2 cities (step1)
  (:action drive_between_cities_step1
    :parameters (?t)
    :precondition (and (truck ?t) (driving ?t) (step1 ?t))
    :effect (and (not (step1 ?t)) (step2 ?t))
  )

  ;; Drive a truck between 2 cities (step2)
  (:action drive_between_cities_step2
    :parameters (?t)
    :precondition (and (truck ?t) (driving ?t) (step2 ?t))
    :effect (and (not (step2 ?t)) (step3 ?t))
  )

  ;; Drive a truck between 2 cities (step3)
  (:action drive_between_cities_step3
    :parameters (?t)
    :precondition (and (truck ?t) (driving ?t) (step3 ?t))
    :effect (and (not (step3 ?t)) (step4 ?t))
  )

  ;; Drive a truck between 2 cities (step4)
  (:action drive_between_cities_step4
    :parameters (?t)
    :precondition (and (truck ?t) (driving ?t) (step4 ?t))
    :effect (and (not (step4 ?t)) (step5 ?t))
  )

  ;; Drive a truck between 2 cities (step5)
  (:action drive_between_cities_step5
    :parameters (?t)
    :precondition (and (truck ?t) (driving ?t) (step5 ?t))
    :effect (and (not (step5 ?t)) (step6 ?t))
  )

  ;; Drive a truck between 2 cities (step6)
  (:action drive_between_cities_step6
    :parameters (?t)
    :precondition (and (truck ?t) (driving ?t) (step6 ?t))
    :effect (and (not (step6 ?t)) (step7 ?t))
  )

  ;; Drive a truck between 2 cities (step7)
  (:action drive_between_cities_step7
    :parameters (?t)
    :precondition (and (truck ?t) (driving ?t) (step7 ?t))
    :effect (and (not (step7 ?t)) (step8 ?t))
  )

  ;; Drive a truck between 2 cities (step8)
  (:action drive_between_cities_step8
    :parameters (?t)
    :precondition (and (truck ?t) (driving ?t) (step8 ?t))
    :effect (and (not (step8 ?t)) (step9 ?t))
  )

  ;; Drive a truck between 2 cities (step9)
  (:action drive_between_cities_step9
    :parameters (?t)
    :precondition (and (truck ?t) (driving ?t) (step9 ?t))
    :effect (and (not (step9 ?t)) (step10 ?t))
  )

  ;; Drive a truck between 2 cities (step10)
  (:action drive_between_cities_step10
    :parameters (?t)
    :precondition (and (truck ?t) (driving ?t) (step10 ?t))
    :effect (and (not (step10 ?t)) (step11 ?t))
  )

  ;; Drive a truck between 2 cities (step11)
  (:action drive_between_cities_step11
    :parameters (?t)
    :precondition (and (truck ?t) (driving ?t) (step11 ?t))
    :effect (and (not (step11 ?t)) (step12 ?t))
  )

  ;; Drive a truck between 2 cities (step12) - arrival
  (:action drive_between_cities_step12
    :parameters (?t)
    :precondition (and (truck ?t) (driving ?t) (step12 ?t))
    :effect (and (not (step12 ?t)) (not (driving ?t)))
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

