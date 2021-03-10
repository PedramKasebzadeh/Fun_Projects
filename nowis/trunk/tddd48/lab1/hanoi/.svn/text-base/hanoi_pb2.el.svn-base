(define (problem hanoi_pb2)
  (:domain hanoi)

  (:objects
    baseA baseB baseC ;; 3 pegs
    disk1 disk2 disk3 disk4 disk5 disk6 disk7 ;; 7 disks
  )

  (:init
   (base baseA) (base baseB) (base baseC)
   (disk disk1) (disk disk2) (disk disk3) (disk disk4) (disk disk5) 
   (disk disk6) (disk disk7)

   (bigger disk2 disk1)
   
   (bigger disk3 disk1) (bigger disk3 disk2)
   
   (bigger disk4 disk1) (bigger disk4 disk2) (bigger disk4 disk3)
   
   (bigger disk5 disk1) (bigger disk5 disk2) (bigger disk5 disk3)
   (bigger disk5 disk4)

   (bigger disk6 disk1) (bigger disk6 disk2) (bigger disk6 disk3)
   (bigger disk6 disk4) (bigger disk6 disk5)
   
   (bigger disk7 disk1) (bigger disk7 disk2) (bigger disk7 disk3)
   (bigger disk7 disk4) (bigger disk7 disk5) (bigger disk7 disk6)

   ;; The actual initial state of the problem, all disk on one peg
   (on disk7 baseA) (on disk6 disk7) (on disk5 disk6) (on disk4 disk5)
   (on disk3 disk4) (on disk2 disk3) (on disk1 disk2)
   (clear disk1) (clear baseB) (clear baseC)
  )

  ;; The goal is to simply a have peg A and B clear
  (:goal (and (clear baseA) (or (clear baseB) (clear baseC))))
)

