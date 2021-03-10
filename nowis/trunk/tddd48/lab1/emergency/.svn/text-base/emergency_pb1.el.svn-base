(define (problem emergency_pb1)
  (:domain emergency)

  (:objects
    base - location
    inj1 - location   ;; location of injuried people
    people1 - location  ;; location of other people

    big - bigcopter
    copter1 - copter

    car1 - carrier

    food1 food2 - food
    med1 med2 - medicine
  )

  (:init
    (at food1 base) (at food2 base)
    
    (at med1 base) (at med2 base)

    (at car1 base)

    (at big base)
    (at copter1 base)
  )

  (:goal
    (and (exists (?x - food) (at ?x people1))
         (exists (?x - food ?y - medicine) (and (at ?x inj1) (at ?y inj1)))
    )
  )
)

