(defdomain uav (

	; Fly the uav to a certain position
	(:operator (!fly-to ?uav ?to)
		((at ?uav ?from))
		((at ?uav ?from))
		((at ?uav ?to))
	)

	; Pick up the given carrier with the large helicopter
	(:operator (!pick-up-carrier ?large ?carr)
		((largeuav ?large) (at ?large ?loc)(at ?carr ?loc) (empty ?large))
		((at ?carr ?loc) (empty ?large))
		((holding ?large ?carr))
	)

	; Put down the carrier held by the large helicopter
	(:operator (!put-down-carrier ?large)
		((at ?large ?loc)(holding ?large ?carr))
		((holding ?large ?carr))
		((at ?carr ?loc) (empty ?large))
	)

	; pick-up type from stock
	(:operator (!pick-up ?type ?uav)
		((at ?uav ?sloc) (supply ?type ?sloc ?q) (call > ?q 0) (empty ?uav))
		((empty ?uav) (supply ?type ?sloc ?q))
		((supply ?type ?sloc (call - ?q 1)) (holding ?uav ?type))
	)

	; Drop crate in a location	
	(:operator (!drop-crate ?uav)
		((at ?uav ?loc) (holding ?uav ?type) (need ?type ?loc ?q) (call > ?q 0) (totalneed ?loc ?t))
		((holding ?uav ?type) (need ?type ?loc ?q) (totalneed ?loc ?t))
		((empty ?uav) (need ?type ?loc (call - ?q 1)) (totalneed ?loc (call - ?t 1)))
	)

	; Put type in the carrier
	(:operator (!load ?type ?uav ?carr)
		((holding ?uav ?type) (at ?uav ?loc) (at ?carr ?loc) (carriercapacity ?cap)
		 (carrierload ?carr ?load) (call > ?cap ?load) (carrierhas ?carr ?type ?q))
		  
		((holding ?uav ?type) (carrierload ?carr ?load) (carrierhas ?carr ?type ?q))

		((empty ?uav) (carrierhas ?carr ?type (call + ?q 1)) (carrierload ?carr (call + ?load 1)))
	)

	; Take type from the carrier
	(:operator (!unload ?type ?uav ?carr)
		((empty ?uav) (at ?uav ?loc) (at ?carr ?loc) (carrierhas ?carr ?type ?q) (call > ?q 0) 
		 (carrierload ?carr ?load))

		((empty ?uav) (carrierload ?carr ?load) (carrierhas ?carr ?type ?q))

		((holding ?uav ?type) (carrierhas ?carr ?type (call - ?q 1)) 
		 (carrierload ?carr (call - ?load 1)) )		
	)

	; Fly the UAV to ?to 
	(:method (fly-to ?uav ?to)
    ALREADY_AT_LOC
	  ((at ?uav ?to))
    nil

    REAL_FLY_TO
    nil
    ((!fly-to ?uav ?to))
  )

	; Deliver all that is required at a location directly,
	; given that at most two crates are required
	(:method (deliver-to-location ?loc)
	  ((totalneed ?loc ?t) (call <= ?t 2))
    ((direct-delivery ?loc))
  )

	; Deliver all that is required at a location using a carrier,
	; given that we need at least two crates
	; (remember you might have more crates than fit on a single carrier,
	;  so you might have to loop)
	(:method (deliver-to-location ?loc)
    ((totalneed ?loc ?t) (call >= ?t 2))
    ((carrier-delivery ?loc))
	)

	; Deliver one crate of a required type directly to ?loc
	(:method (direct-delivery ?loc)
	  NEED-SOMETHING
	  ((empty ?uav) (need ?type ?loc ?f) (call > ?f 0) (depot ?d))
    ((fly-to ?uav ?d) (!pick-up ?type ?uav) 
     (fly-to ?uav ?loc) (!drop-crate ?uav)
     (direct-delivery ?loc)
    )

    STOP
    ((totalneed ?loc ?t) (call = ?t 0))
    nil
	)

	; Pack and deliver a carrier with contents to a location.
	; Carriers can only be loaded at depots, so you may have 
	; to move it there first!
	(:method (carrier-delivery ?loc)
    MOVE_CARR_TO_DEPOT
    ((depot ?d) (carrier ?carr) (not (at ?carr ?d)) 
     (empty ?uav) (largeuav ?uav) (at ?carr ?carloc)
    )
    ((fly-to ?uav ?carloc) (!pick-up-carrier ?uav ?carr) (fly-to ?uav ?d)
     (!put-down-carrier ?uav) (carrier-delivery ?loc) 
    )
    
    PACK_MOVE_UNPACK
    ((depot ?d) (carrier ?carr) (at ?carr ?d) (at ?uav ?d) 
     (empty ?uav) (largeuav ?uav))
    ((load-carrier-for ?carr ?loc) (!pick-up-carrier ?uav ?carr)
     (fly-to ?uav ?loc) (!put-down-carrier ?uav) (unload-carrier ?carr ?loc)
    )
  )

	; Load whatever you need for the given destination location.
	; Remember that there can already be crates on the carrer!
	; Also, you can't load more than the carrier's capacity at any given time.
	; Should only  be applicable if the carrier is at a supply location.
	(:method (load-carrier-for ?carr ?loc)
    PACK
	  ((depot ?d) (at ?carr ?d) (empty ?uav) (at ?uav ?d)
     (need ?type ?loc ?t) (call > ?t 0) 
     (carriercapacity ?cap) (carrierload ?carr ?load) (call < ?load ?cap)
    )
    ((!pick-up ?type ?uav) (!load ?type ?uav ?carr)
     (load-carrier-for ?carr ?loc)
    )
    
    STOP
    nil
    nil
	)

	; Unload the carrier, assuming that you're already at ?loc
	; (the carrier might already be empty!)
	(:method (unload-carrier ?carr ?loc)
	  UNPACK
    ((at ?carr ?loc) (empty ?uav) (at ?uav ?loc) 
     (carrierhas ?carr ?type ?load) (call > ?load 0)
    )
    ((!unload ?type ?uav ?carr) (!drop-crate ?uav) (unload-carrier ?carr ?loc))

    STOP
    nil
    nil
  )
 )
)

