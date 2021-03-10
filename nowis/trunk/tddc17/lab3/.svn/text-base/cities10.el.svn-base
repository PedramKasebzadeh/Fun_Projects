;; 4 package
;; 2 from the same office (big and small), have to be delivred to same loc.
(define (problem C3_2)
  (:domain logistics)

  (:objects
   city1 city2 city3 city4 city5 city6 city7 city8 city9 city10
   truck1 truck2 truck3 truck4       ;; one truck in each city,
   train1                            ;; one train
   airplane1                         ;; only one airplane,
   office1 office2 office3 office4 office5 office6 office7 office8 office9
   office10
   trainStation2 trainStation3 trainStation4
                                     ;; trainstation (city2, city3, city4)
   airport1 airport2 airport5 airport6 airport7 airport8 airport9 airport10
   packet1 packet2 packet3 packet4   ;; four packages to be delivered
  )

  (:init
   ;; Type declarations:
   (object packet1) (object packet2) (object packet3) (object packet4)
   (small_s packet1) (small_s packet2) (big_s packet3) (big_s packet4)

   ;; all vehicles must be declared as both "vehicle" and their
   ;; appropriate subtype,
   (vehicle truck1) (vehicle truck2) (vehicle truck3) (vehicle truck4)
   (vehicle train1)
   (vehicle airplane1)
   (truck truck1) (truck truck2) (truck truck3) (truck truck4)
   (train train1)
   (airplane airplane1)

   ;; likewise, airports must be declared both as "location" and as
   ;; the subtype "airport".
   ;; idem for train stations
   (location office1) (location office2) (location office3) (location office4)
   (location office5) (location office6) (location office7) (location office8)
   (location office9) (location office10)
   (location trainStation2) (location trainStation3) (location trainStation4)
   (location airport1) (location airport2) (location airport5)
   (location airport6) (location airport7) (location airport8)
   (location airport9) (location airport10)
   (trainStation trainStation2) (trainStation trainStation3)
   (trainStation trainStation4)
   (airport airport1) (airport airport2) (airport airport5)
   (airport airport6) (airport airport7) (airport airport8)
   (airport airport9) (airport airport10)
   (city city1) (city city2) (city city3) (city city4) (city city5) (city city6)
   (city city7) (city city8) (city city9) (city city10)
                              
   ;; "loc" defines the topology of the problem,
   (loc office1 city1) (loc airport1 city1)
   (loc office2 city2) (loc airport2 city2) (loc trainStation2 city2)
   (loc office3 city3) (loc trainStation3 city3)
   (loc office4 city4) (loc trainStation4 city4)
   (loc office5 city5) (loc airport5 city5)
   (loc office6 city6) (loc airport6 city6)
   (loc office7 city7) (loc airport7 city7)
   (loc office8 city8) (loc airport8 city8)
   (loc office9 city9) (loc airport9 city9)
   (loc office10 city10) (loc airport10 city10)

   ;; The actual initial state of the problem, which specifies the
   ;; initial locations of all packages and all vehicles:
   (at packet1 office1)
   (at packet2 office3)
   (at packet3 office4)
   (at packet4 office3)
   (at truck1 airport1)
   (at truck2 airport2)
   (at truck3 office3)
   (at truck4 trainStation4)
   (at train1 trainStation2)
   (at airplane1 airport1)
  )

  ;; The goal is to have the four packages delivered to their destinations:
  (:goal (and (at packet1 office2) (at packet2 office2) (at packet3 office1)
              (at packet4 office2)
         )
  )
)
