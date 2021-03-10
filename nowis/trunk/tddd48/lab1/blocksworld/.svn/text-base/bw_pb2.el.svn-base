(define (problem bw_pb1)
  (:domain blocks_world)

  (:objects
    b1 b2 b3 b4 b5 b6
  )
 
  (:init
    (clear b1)
   
    (on b1 b2) (on b2 b3) (on b3 b4) (on b4 b5) (on b5 b6)
     
    (on-table b6)

    (leftToRightCrane b1) (leftToRightCrane b2) (leftToRightCrane b3)
    (leftToRightCrane b4) (leftToRightCrane b5) (leftToRightCrane b6) 

    (rightToLeftCrane b1) (rightToLeftCrane b2) (rightToLeftCrane b3)
    (rightToLeftCrane b4) (rightToLeftCrane b5) (rightToLeftCrane b6) 
  )

  (:goal
    (and (clear b1) (clear b2) (clear b3) (clear b4) (clear b5) (clear b6))
  )
)

