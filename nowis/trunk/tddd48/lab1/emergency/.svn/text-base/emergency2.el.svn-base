;; This is the same definition as in emergency.el except the move action take
;; more time step to be executed
;; If not, the planner will never use the carriers because moving in one time
;; step make the action of pick-up, moving, put-down quicker than using the
;; carrier

(define (domain emergency)
  (:requirements :adl)

  (:types location copter bigcopter food medicine carrier)

  (:predicates
    (at ?x - (either copter bigcopter food medicine carrier) ?loc - location)
    (in ?x - (either food medicine) ?c - carrier)
    (handle ?x - (either copter bigcopter) ?y - (either food medicine carrier))
    (loaded ?x - (either copter bigcopter))

    ;; when food or medicine is in a carrier, they musn't be at any location,
    ;; only the carrier will be at a location
    ;;
    ;; when a carrier, food or medicine are handled by a copter, they also
    ;; musn't be at any location, only the copter will be at a location
   
    ;; make move action longer (3 time steps) 
    (moving ?x - (either copter bigcopter))
    (moving1 ?x - (either copter bigcopter))
    (moving2 ?x - (either copter bigcopter))
  )

  (:action move
    :parameters (?x    - (either copter bigcopter)
                 ?from - location
                 ?to   - location
                )
    :precondition (at ?x ?from)
    :effect (and (not (at ?x ?from)) (at ?x ?to) (moving ?x) (moving1 ?x))
  )

  (:action move1
    :parameters (?x - (either copter bigcopter))
    :precondition (moving1 ?x)
    :effect (and (not (moving1 ?x)) (moving2 ?x))
  )

  (:action move2
    :parameters (?x - (either copter bigcopter))
    :precondition (moving2 ?x)
    :effect (and (not (moving2 ?x)) (not (moving ?x)))
  )



  (:action pick-up-crate
    :parameters (?x   - (either copter bigcopter)
                 ?c   - (either food medicine)
                 ?loc - location
                )
    :precondition (and (not (loaded ?x)) (not (moving ?x))
                       (at ?x ?loc) (at ?c ?loc))
    :effect (and (not (at ?c ?loc)) (handle ?x ?c) (loaded ?x))
  )

  (:action pick-up-carrier
    :parameters (?x   - bigcopter
                 ?c   - carrier
                 ?loc - location
                )
    :precondition (and (not (loaded ?x)) (not (moving ?x))
                       (at ?x ?loc) (at ?c ?loc))
    :effect (and (not (at ?c ?loc)) (handle ?x ?c) (loaded ?x))
  )

  (:action put-down
    :parameters (?x   - (either copter bigcopter)
                 ?c   - (either carrier food medicine)
                 ?loc - location
                )
    :precondition (and (handle ?x ?c) (at ?x ?loc) (not (moving ?x)))
    :effect (and (at ?c ?loc) (not (handle ?x ?c)) (not (loaded ?x)))
  )

  (:action pick-up-from-carrier
    :parameters (?x   - (either copter bigcopter)
                 ?c   - (either food medicine)
                 ?car - carrier
                 ?loc - location
                )
    :precondition (and (at ?x ?loc) (at ?car ?loc) (in ?c ?car) 
                       (not (moving ?x)) (not (loaded ?x))
                  )
    :effect (and (not (in ?c ?car)) (loaded ?x) (handle ?x ?c))
  )

  (:action put-down-in-carrier
    :parameters (?x   - (either copter bigcopter)
                 ?c   - (either food medicine)
                 ?car - carrier
                 ?loc - location
                )
    :precondition (and (at ?x ?loc) (at ?car ?loc) (handle ?x ?c)
                       (not (moving ?x))
                   )
    :effect (and (in ?c ?car) (not (loaded ?x)) (not (handle ?x ?c)))
  )
)

