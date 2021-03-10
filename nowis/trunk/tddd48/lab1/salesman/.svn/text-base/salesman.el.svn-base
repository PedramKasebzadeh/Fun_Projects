(define (domain salesman)
  (:requirements :adl)

  (:types location bus train airplane salesman)

  (:predicates
    (at ?x - (either bus train airplane salesman) ?loc - location)
  
    (visited ?s - salesman ?loc - location)

    (road ?l1 ?l2 - location ?x - (either bus train airplane))
  )

  (:action move
    :parameters (?s    - salesman
                 ?x    - (either bus train airplane)
                 ?from - location
                 ?to   - location
                )
    :precondition (and (at ?s ?from) (at ?x ?from)
                       (or (road ?from ?to ?x) (road ?to ?from ?x))
                  )
    :effect (and (not (at ?s ?from)) (at ?s ?to)
                 (not (at ?x ?from)) (at ?x ?to)
                 (visited ?s ?to)
            )
  )

  (:action move_empty
    :parameters (?x    - (either bus train airplane)
                 ?from - location
                 ?to   - location
                )
    :precondition (and (at ?x ?from) 
                       (or (road ?from ?to ?x) (road ?to ?from ?x))
                  )
    :effect (and (not (at ?x ?from)) (at ?x ?to))
  )
)

