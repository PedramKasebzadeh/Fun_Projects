(define (problem emergency_pb2)
  (:domain emergency)

  ;; designed to use the carrier
  ;; The planner will never use the carrier because it's too easy to move
  ;; It should take more time steps to move to make this model more close to
  ;; reality. (see emergency2.el problem definition)
  (:objects
    base - location
    inj1 - location   ;; location of injuried people

    big - bigcopter

    car1 - carrier

    food1 food2 food3 - food
    med1 med2 med3 - medicine
  )

  (:init
    (at food1 base) (at food2 base) (at food3 base)
    
    (at med1 base) (at med2 base) (at med3 base)

    (at car1 base)

    (at big base)
  )

  (:goal
    (and (exists (?x ?y - food ?t ?u - medicine) 
                 (and (not (= ?x ?y)) (not (= ?t ?u))
                      (at ?x inj1) (at ?y inj1) (at ?t inj1) (at ?u inj1))
         )
    )
  )
)

