package net.datastructures;

public class QuadraticProbingHashTableMap<K, V> extends HashTableMap<K, V> {

	public QuadraticProbingHashTableMap() {
		super(1021);
	}
	
	public QuadraticProbingHashTableMap(int cap) {
		super(cap);
	}
	
	protected int findEntry(K key) throws InvalidKeyException {
		checkKey(key);
		
		int nbCollisions = 0;
		int avail = -1;
		int keyHashValue = hashValue(key);
		int currentIndex = keyHashValue;
		
		do {
			Entry<K,V> e = bucket[currentIndex];
			
			if ( e == null) {
				if (avail < 0)
					avail = currentIndex;	// key is not in table
				break;
			}
			
			if (key.equals(e.getKey())) // we have found our key
				return currentIndex;	// key found
			
			if (e == AVAILABLE) {	// bucket is deactivated
				if (avail < 0)
					avail = currentIndex;	// remember that this slot is available
			}

			nbCollisions++;
			currentIndex = (keyHashValue + (nbCollisions*nbCollisions)) % capacity;	// keep looking
		} while (nbCollisions < capacity);
		
		nbProbes = nbCollisions + 1;
		return -(avail + 1);  // first empty or available slot
	}
	
	/** Put a key-value pair in the map, replacing previous one if it exists.
	 *  overidding to avoid rehashing  */
	public V put (K key, V value) throws InvalidKeyException {
		int i = findEntry(key); //find the appropriate spot for this entry
		
		if (i >= 0)	{ //  this key has a previous value 
			if(getNbProbes() > capacity) // table at least half full, this pair cannot be inserted (this shouldn't happen if reshashing is active)
				throw new InvalidKeyException("The table is at least half-full, this pair <key, value> cannot be inserted ");
			return ((HashEntry<K,V>) bucket[i]).setValue(value); // set new value
		}
		
		bucket[-i-1] = new HashEntry<K,V>(key, value); // convert to proper index
		n++;
		return null; 	// there was no previous value
	}

	/** Avoid rehashing */
	protected void rehash() {}
}
