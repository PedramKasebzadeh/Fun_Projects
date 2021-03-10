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
  )

  (:action move
    :parameters (?x    - (either copter bigcopter)
                 ?from - location
                 ?to   - location
                )
    :precondition (at ?x ?from)
    :effect (and (not (at ?x ?from)) (at ?x ?to))
  )

  (:action pick-up-crate
    :parameters (?x   - (either copter bigcopter)
                 ?c   - (either food medicine)
                 ?loc - location
                )
    :precondition (and (not (loaded ?x)) (at ?x ?loc) (at ?c ?loc))
    :effect (and (not (at ?c ?loc)) (handle ?x ?c) (loaded ?x))
  )

  (:action pick-up-carrier
    :parameters (?x   - bigcopter
                 ?c   - carrier
                 ?loc - location
                )
    :precondition (and (not (loaded ?x)) (at ?x ?loc) (at ?c ?loc))
    :effect (and (not (at ?c ?loc)) (handle ?x ?c) (loaded ?x))
  )

  (:action put-down
    :parameters (?x   - (either copter bigcopter)
                 ?c   - (either carrier food medicine)
                 ?loc - location
                )
    :precondition (and (handle ?x ?c) (at ?x ?loc))
    :effect (and (at ?c ?loc) (not (handle ?x ?c)) (not (loaded ?x)))
  )

  (:action pick-up-from-carrier
    :parameters (?x   - (either copter bigcopter)
                 ?c   - (either food medicine)
                 ?car - carrier
                 ?loc - location
                )
    :precondition (and (at ?x ?loc) (at ?car ?loc) (in ?c ?car) 
                       (not (loaded ?x))
                  )
    :effect (and (not (in ?c ?car)) (loaded ?x) (handle ?x ?c))
  )

  (:action put-down-in-carrier
    :parameters (?x   - (either copter bigcopter)
                 ?c   - (either food medicine)
                 ?car - carrier
                 ?loc - location
                )
    :precondition (and (at ?x ?loc) (at ?car ?loc) (handle ?x ?c))
    :effect (and (in ?c ?car) (not (loaded ?x)) (not (handle ?x ?c)))
  )
)

