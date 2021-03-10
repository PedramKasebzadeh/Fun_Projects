(define (problem hanoi_pb3)
  (:domain hanoi)

  (:objects
    ;; problem must be unsovable
    baseA baseB ;; 2 pegs
    disk1 disk2 disk3;; 3 disks
  )

  (:init
   (base baseA) (base baseB)
   (disk disk1) (disk disk2) (disk disk3)

   (bigger disk2 disk1)
   
   ;; The actual initial state of the problem, all disk on one peg
   (on disk3 baseA) (on disk2 disk3) (on disk1 disk2)
   (clear disk1) (clear baseB)
  )

  ;; The goal is to simply a have peg A clear
  (:goal (clear baseA))
)

