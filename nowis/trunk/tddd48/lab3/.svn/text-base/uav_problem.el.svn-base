(defproblem problem uav
	(
		(uav heli1)
		(uav bigheli)
		(largeuav bigheli)
		(carrier carr1)

		(location l1)
		(location l2)
		(location l3)
		(location l4)
		(location l5)

		(depot l5)

		(need medicine l1 5)
		(need medicine l2 1)
		(need medicine l3 1)
		(need medicine l4 0)
		(need medicine l5 0)

		(need food l1 2)
		(need food l2 4)
		(need food l3 0)
		(need food l4 1)
		(need food l5 0)

		(totalneed l1 7)
		(totalneed l2 5)
		(totalneed l3 1)
		(totalneed l4 1)
		(totalneed l5 0)

		(supply medicine l5 10)
		(supply food l5 10)
	
		(carriercapacity 4)

		(carrierload carr1 0)
		(carrierhas carr1 food 0)
		(carrierhas carr1 medicine 0)

		(at heli1 l5)
		(at bigheli l5)
		(at carr1 l5)
		
		(empty heli1)
		(empty bigheli)		
	)

	(:unordered
		(deliver-to-location l1)
		(deliver-to-location l2)
		(deliver-to-location l3)		
		(deliver-to-location l4)
	)
)
