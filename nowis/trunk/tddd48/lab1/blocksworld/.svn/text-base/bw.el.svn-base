(define (domain blocks_world)
  (:requirements :adl)

  (:predicates 
    (on-table ?x) 
    (on ?x ?y) 
    (clear ?x)
    (left ?x ?y) ;; ?x on the left of ?y

    (leftToRightCrane ?x) ;; ?x on the left of the right crane
    (rightToLeftCrane ?x) ;; ?x on the right of the left crane
  )

  ;; move block ?x from ?y to the left limit with left crane
  (:action LeftCrane_MoveToTable
    :parameters (?x ?y)
    :precondition (and (leftToRightCrane ?x) (clear ?x) (on ?x ?y))
    :effect (and (clear ?y) (on-table ?x) (not (on ?x ?y))
                 (forall (?a) (and (left ?x ?a) (rightToLeftCrane ?a)))
            )
  )

  ;; move block ?x from ?y to the right limit with right crane
  (:action RightCrane_MoveToTable
    :parameters (?x ?y)
    :precondition (and (rightToLeftCrane ?x) (clear ?x) (on ?x ?y))
    :effect (and (clear ?y) (on-table ?x) (not (on ?x ?y))
                 (forall (?a) (and (left ?a ?x) (leftToRightCrane ?a)))
            )
  )

  ;; move block ?x from ?y to ?z with left crane
  (:action LeftCrane_MoveFromStackToBlock
    :parameters (?x ?y ?z)
    :precondition (and (leftToRightCrane ?x) (leftToRightCrane ?z)
                       (clear ?x) (clear ?z) (on ?x ?y)
                  )
    :effect (and (clear ?y) (on ?x ?z) (not (clear ?z)) (not (on ?x ?y))
                 (forall (?a) (when (left ?a ?z) 
                                (and (left ?a ?x) (not (left ?x ?a))
                                     (leftToRightCrane ?a)
                                )
                              )
                 )
                 (forall (?a) (when (not (left ?a ?z))
                                (and (not (left ?a ?x)) (left ?x ?a)
                                     (rightToLeftCrane ?a)
                                )
                              )
                 )
            )
  )

  ;; move block ?x from ?y to ?z with right crane
  (:action RightCrane_MoveFromStackToBlock
    :parameters (?x ?y ?z)
    :precondition (and (rightToLeftCrane ?x) (rightToLeftCrane ?z)
                       (clear ?x) (clear ?z) (on ?x ?y)
                  )
    :effect (and (clear ?y) (on ?x ?z) (not (clear ?z)) (not (on ?x ?y))
                 (forall (?a) (when (left ?z ?a) 
                                (and (left ?x ?a) (not (left ?a ?x))
                                     (rightToLeftCrane ?a)
                                )
                              )
                 )
                 (forall (?a) (when (not (left ?z ?a))
                                (and (not (left ?x ?a)) (left ?a ?x)
                                     (leftToRightCrane ?a)
                                )
                              )
                 )
            )
  )

  ;; move block ?x from table to ?z with left crane
  (:action LeftCrane_MoveFromTableToBlock
    :parameters (?x ?z)
    :precondition (and (leftToRightCrane ?x) (leftToRightCrane ?z)
                       (clear ?x) (clear ?Z) (on-table ?x)
                  )
    :effect (and (on ?x ?z) (not (clear ?z)) (not (on-table ?x))
                 (not (rightToLeftCrane ?x))
                 (forall (?a) (when (left ?a ?z) 
                                (and (left ?a ?x) (not (left ?x ?a))
                                     (leftToRightCrane ?a)
                                )
                              )
                 )
                 (forall (?a) (when (not (left ?a ?z))
                                (and (not (left ?a ?x)) (left ?x ?a)
                                     (rightToLeftCrane ?a)
                                )
                              )
                 )
            )
  )

  ;; move block ?x from table to ?z with right crane
  (:action RightCrane_MoveFromTableToBlock
    :parameters (?x ?z)
    :precondition (and (rightToLeftCrane ?x) (rightToLeftCrane ?z)
                       (clear ?x) (clear ?z) (on-table ?x)
                  )
    :effect (and (on ?x ?z) (not (clear ?z)) (not (on-table ?x))
                 (not (leftToRightCrane ?x))
                 (forall (?a) (when (left ?z ?a) 
                                (and (left ?x ?a) (not (left ?a ?x))
                                     (rightToLeftCrane ?a)
                                )
                              )
                 )
                 (forall (?a) (when (not (left ?z ?a))
                                 (and (not (left ?x ?a)) (left ?a ?x)
                                      (leftToRightCrane ?a)
                                 )
                              )
                 )
            )
  )
)

