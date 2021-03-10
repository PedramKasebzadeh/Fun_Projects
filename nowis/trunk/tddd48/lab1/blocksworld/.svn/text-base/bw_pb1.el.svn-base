(define (problem bw_pb1)
  (:domain blocks_world)

  (:objects
    b1 b2 b3 b4 b5 b6
  )
 
  (:init
    (clear b1) (clear b2) (clear b3) (clear b4) (clear b5) (clear b6)
    
    (on-table b1) (on-table b2) (on-table b3) (on-table b4) (on-table b5) 
    (on-table b6)

    (left b1 b2) (left b1 b3) (left b1 b4) (left b1 b5) (left b1 b6)
    (left b2 b3) (left b2 b4) (left b2 b5) (left b2 b6)
    (left b3 b4) (left b3 b5) (left b3 b6)
    (left b4 b5) (left b4 b6)
    (left b5 b6)

    (leftToRightCrane b1) (leftToRightCrane b2) (leftToRightCrane b3)
    (leftToRightCrane b4) (leftToRightCrane b5) (leftToRightCrane b6) 

    (rightToLeftCrane b1) (rightToLeftCrane b2) (rightToLeftCrane b3)
    (rightToLeftCrane b4) (rightToLeftCrane b5) (rightToLeftCrane b6) 
  )

  (:goal
    (and (on b1 b2) (on b2 b3) (on b3 b4) (on b4 b5) (on b5 b6))
  )
)

