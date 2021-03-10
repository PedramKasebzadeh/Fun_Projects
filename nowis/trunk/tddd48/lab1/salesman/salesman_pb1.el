(define (problem pb1)
  (:domain salesman)

  (:objects
    loc1 loc2 loc3 loc4 loc5 loc6 - location

    b1 b2 - bus
    t1 - train
    a1 a2 - airplane

    s1 s2 - salesman
  )

  (:init
    (road loc1 loc2 a1) (road loc5 loc6 a2)
    (road loc2 loc3 b1) (road loc2 loc4 b1) (road loc5 loc6 b2)
    (road loc4 loc6 t1)

    (at a1 loc1)
    (at a2 loc6)
    (at b1 loc4)
    (at b2 loc6)
    (at t1 loc6)

    (at s1 loc1)
    (at s2 loc1)
  )

  (:goal
    (and (at s1 loc1) (visited s1 loc5) (visited s1 loc6) (visited s1 loc2)
         (at s2 loc3) (visited s2 loc4) (visited s2 loc5)
    )
  )
)

