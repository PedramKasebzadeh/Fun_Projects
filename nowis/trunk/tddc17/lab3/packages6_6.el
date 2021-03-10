;; 4 package
;; 2 from the same office (big and small), have to be delivred to same loc.
(define (problem C3_2)
  (:domain logistics)

  (:objects
   city1 city2 city3 city4           ;; there are four cities,
   truck1 truck2 truck3 truck4       ;; one truck in each city,
   train1                            ;; one train
   airplane1                         ;; only one airplane,
   office1 office2 office3 office4   ;; offices are "non-airport" locations
   trainStation2 trainStation3 trainStation4
                                     ;; trainstation (city2, city3, city4)
   airport1 airport2                 ;; two airport (city1 and city2)
   packet1 packet2 packet3 packet4   ;; four packages to be delivered
   packet5 packet6 
  )

  (:init
   ;; Type declarations:
   (object packet1) (object packet2) (object packet3) (object packet4)
   (object packet5) (object packet6)
   (small_s packet1) (small_s packet2) (big_s packet3) (big_s packet4)
   (small_s packet5) (small_s packet6)

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
   (location trainStation2) (location trainStation3) (location trainStation4)
   (location airport1) (location airport2)
   (trainStation trainStation2) (trainStation trainStation3)
   (trainStation trainStation4)
   (airport airport1) (airport airport2)
   (city city1) (city city2) (city city3) (city city4)

   ;; "loc" defines the topology of the problem,
   (loc office1 city1) (loc airport1 city1)
   (loc office2 city2) (loc airport2 city2) (loc trainStation2 city2)
   (loc office3 city3) (loc trainStation3 city3)
   (loc office4 city4) (loc trainStation4 city4)

   ;; The actual initial state of the problem, which specifies the
   ;; initial locations of all packages and all vehicles:
   (at packet1 office1)
   (at packet2 office3)
   (at packet3 office4)
   (at packet4 office3)
   (at packet5 office2)
   (at packet6 office3)
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

