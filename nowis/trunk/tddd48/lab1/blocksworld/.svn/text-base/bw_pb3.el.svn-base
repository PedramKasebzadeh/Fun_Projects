(define (problem bw_pb2)
  (:domain blocks_world)

  (:objects
    b1 b2 b3 b4 b5 b6
  )
 
  (:init
    (clear b3) (clear b5) (clear b6)
   
    (on b4 b1) (on b5 b4) (on b6 b2)
     
    (on-table b1) (on-table b2) (on-table b3)

    (leftToRightCrane b1) (leftToRightCrane b2) (leftToRightCrane b3)
    (leftToRightCrane b4) (leftToRightCrane b5) (leftToRightCrane b6) 

    (rightToLeftCrane b1) (rightToLeftCrane b2) (rightToLeftCrane b3)
    (rightToLeftCrane b4) (rightToLeftCrane b5) (rightToLeftCrane b6) 
  )

  (:goal
    (and (on b3 b1) (on b2 b4) (on-table b4) (on-table b6)) 
  )
)

