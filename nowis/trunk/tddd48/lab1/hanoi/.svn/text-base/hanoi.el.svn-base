(define (domain hanoi)
  (:requirements :strips :disjunctive-preconditions)

  (:predicates
    ;; Static predicates
    (disk ?d)
    (base ?b)
    (bigger ?d1 ?d2) ;; disk ?d1 is bigger than disk ?d2

    ;; Non-static predicates
    (on ?d1 ?d2) ;; disk ?d1 on disk ?d2
    (clear ?d) ;; disk ?d is empty
  )

  ;; move disk ?p from peg p1 to peg ?p2
  (:action move
    :parameters (?d ?from ?to)
    :precondition
      (and (disk ?d) ;; ?d is a disk and can be moved
           (clear ?d) ;; ?d is the top of its peg
           (on ?d ?from) ;; ?d is at selected location
           (clear ?to) ;; ?to is the top of its peg
           (or (bigger ?to ?d) ;; ?d is bigger than the destination disk ?p
               (base ?to) ;; or ?to is a base
           )
      )
    :effect
      (and (clear ?from) (not (on ?d ?from)) ;; ?d is not more at ?from
           (on ?d ?to) (not (clear ?to)) ;; ?d is at ?to
      )
  )
)

