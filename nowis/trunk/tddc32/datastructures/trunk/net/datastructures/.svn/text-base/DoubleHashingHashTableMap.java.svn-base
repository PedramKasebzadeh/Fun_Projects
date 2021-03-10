package net.datastructures;

public class DoubleHashingHashTableMap<K, V> extends HashTableMap<K, V> {
	public static final int DEFAULT_Q = 421;
	public static final int DEFAULT_CAPACITY = 1021;

	private int q = DEFAULT_Q;

	public DoubleHashingHashTableMap() {
		super(DEFAULT_CAPACITY);
	}

	/**
	 * @param cap
	 * @param q must be a prime number
	 */
	public DoubleHashingHashTableMap(int cap, int q) {
		super(cap);

		if (q >= cap) {
			throw new IllegalArgumentException("q()" + q + ") must be lesser than capacity(" + cap + ")");
		}

		this.q = q;
	}

	private int secondaryHashFunction(K key) {
		return q - (key.hashCode() % q);
	}

	/** Hash function applying double hash method. */
	private int doubleHashValue(K key, int nbCollisions) {
		return Math.abs(((key.hashCode() % capacity) + nbCollisions*secondaryHashFunction(key)) % capacity);
	}

	protected int findEntry(K key) {
		checkKey(key);

		int nbCollisions = 0;
		int avail = -1;
		int currentIndex = doubleHashValue(key, nbCollisions);

		do {
			Entry<K, V> e = bucket[currentIndex];

			if (e == null) {
				if (avail < 0)
					avail = currentIndex; // key is not in table
				break;
			}

			if (key.equals(e.getKey())) // we have found our key
				return currentIndex;	// key found
			
			if (e == AVAILABLE) {	// bucket is deactivated
				if (avail < 0)
					avail = currentIndex;	// remember that this slot is available
			}
				
			nbCollisions++;	
			currentIndex = doubleHashValue(key, nbCollisions);	// keep looking
		} while (nbCollisions < capacity);

		nbProbes = nbCollisions + 1;
		return -(avail + 1);  // first empty or available slot
	}
}
