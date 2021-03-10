(define (problem emergency_pb2)
  (:domain emergency)

  (:objects
    base - location
    inj1 inj2 - location   ;; location of injuried people

    big - bigcopter
    copter1 copter2 - copter

    car1 - carrier

    food1 food2 food3 food4 - food
    med1 med2 med3 - medicine
  )

  (:init
    (at food1 base) (at food2 base) (at food3 base) (at food4 base)
    
    (at med1 base) (at med2 base) (at med3 base)

    (at car1 base)

    (at big base) (at copter1 base) (at copter2 base)
  )

  (:goal
    (and (exists (?x - food ?y - medicine) (and (at ?x inj1) (at ?y inj1)))
         (exists (?x - food ?y - medicine) (and (at ?x inj2) (at ?y inj2)))
    )
  )
)

