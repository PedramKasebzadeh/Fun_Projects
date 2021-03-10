(define (problem hanoi_pb1)
  (:domain hanoi)

  (:objects
    baseA baseB baseC ;; 3 pegs
    disk1 disk2 disk3 ;; 3 disks
  )

  (:init
   (base baseA) (base baseB) (base baseC)
   (disk disk1) (disk disk2) (disk disk3)

   (bigger disk2 disk1)
   
   (bigger disk3 disk1) (bigger disk3 disk2)
   
   ;; The actual initial state of the problem, all disk on one peg
   (on disk3 baseA) (on disk2 disk3) (on disk1 disk2)
   (clear disk1) (clear baseB) (clear baseC)
  )

  ;; The goal is to simply a have peg A and B clear
  (:goal (and (clear baseA) (or (clear baseB) (clear baseC))))
)

