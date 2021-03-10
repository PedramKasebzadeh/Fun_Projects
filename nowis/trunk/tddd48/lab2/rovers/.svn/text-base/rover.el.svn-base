(define (domain simplerover)
  (:requirements :typing)

  (:types rover location data)

  (:predicates
    (at ?rover - rover ?location - location)
    (acquired ?d - data)
    (sent ?d - data)
    (path-between ?a ?b - location)
    (sending ?r - rover)
  )

  (:action drive
    :parameters (?r - rover ?from ?to - location)
    :precondition (and (at ?r ?from) (path-between ?from ?to))
    :effect (and (not (at ?r ?from)) (at ?r ?to))
  )

  ;; send data and put sending to true // avoid concurent sending data
  (:action send
    :parameters (?r - rover ?d - data ?loc - location)
    :precondition (and (acquired ?d) (at ?r ?loc) (not (sending ?r)))
    :effect (and (sent ?d) (sending ?r))
  )

  ;; simply reset sending
  (:action reset-sending
    :parameters (?r - rover)
    :precondition (sending ?r)
    :effect (not (sending ?r))
  )
)

