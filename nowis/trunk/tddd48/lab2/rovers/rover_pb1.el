(define (problem rover1)
  (:domain simplerover)
  (:objects d1 d2 d3 d4 - data r1 - rover loc1 - location)
  (:init (acquired d1) (acquired d2) (acquired d3) (at r1 loc1))
  (:goal (and (sent d1) (sent d2) (sent d3)))
)

