#objects :domain uav :elements { heli1 }
#objects :domain largeuav :elements { bigheli } // implicitly an UAV as well
#objects :domain carrier :elements { carr1 }
#objects :domain location :elements { l<1..2>}
#objects :domain depot :elements { l2 }
#objects :domain type :elements { medicine, food }

// Initialize resources.  In each state, we have an "incoming" amount
// of resources, denoted by $init(resource).  We also have an amount
// produced, an amount consumed, and so on.

#dom [0] $init(need(medicine, l1)) == 3
#dom [0] $init(need(medicine, l2)) == 0
#dom [0] $init(need(food, l1)) == 2
#dom [0] $init(need(food, l2)) == 0

#dom [0] $init(supply(medicine, l1)) == 0
#dom [0] $init(supply(medicine, l2)) == 10
#dom [0] $init(supply(food, l1)) == 0
#dom [0] $init(supply(food, l2)) == 10

// Initialize the total number of crates required by summing over the
// different types we have available ($sum is "big sigma").

#dom forall location [
	[0] $init(totalneed(location)) == $sum(<type>, true, $init(need(type, location)))
]

// Initialize the available space for each carrier to 4.

#dom forall carrier, type [
	[0] $init(carrierspace(carrier)) == 4 &
	[0] $init(carrierhas(carrier, type)) == 0
]

// Weird syntax that should be changed some time...
#init :feature at :value false :exception :value true :features {
	at(heli1, l2),
	at(bigheli, l2),
	at(carr1, l2)
}

#dom [0] forall uav [ empty(uav) ]
#dom [0] forall uav, type-or-thing [ !holding(uav, type-or-thing) ]

#resgoal forall location [ totalneed(location) == 0 ]

// Initializes min and max values for certain resources.
// Actions aren't allowed to go outside these limits
// when they produce and consume resources.
// You can mostly ignore this
#dom forall type, location, carrier [
	[0] $minimum(need(type, location)) == 0 &
	[0] $maximum(need(type, location)) == 9999 &
	[0] $minimum(supply(type, location)) == 0 &
	[0] $maximum(supply(type, location)) == 9999 &
	[0] $minimum(totalneed(location)) == 0 &
	[0] $maximum(totalneed(location)) == 9999 &
	[0] $minimum(carrierhas(carrier, type)) == 0 &
	[0] $maximum(carrierhas(carrier, type)) == 9999 &
	[0] $minimum(carrierspace(carrier)) == 0 &
	[0] $maximum(carrierspace(carrier)) == 9999
]

