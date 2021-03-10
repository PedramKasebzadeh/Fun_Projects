import java.awt.Color;
import java.io.IOException;

import net.datastructures.DoubleHashingHashTableMap;
import net.datastructures.HashTableMap;
import net.datastructures.InvalidKeyException;
import net.datastructures.QuadraticProbingHashTableMap;

/**
 * Prime numbers list :
 * 421
 * 1021
 * 5701
 */
public class TestHashMap {
	public static final String DICTIONARY = "some-unique-words.txt";
	public static final int CAPACITY = 1021;
	public static final int DOUBLE_HASHING_Q = 421;
	public static final int NB_TESTS = 20;
	public static final int MAX_PERCENT = 100;
	
	private static long start = 0;
	
	public static void main(String[] args) throws IOException {
		Plot2D plot;
		DictionaryInputReader is = new DictionaryInputReader(DICTIONARY);
		String[] words = new String[CAPACITY];
		int[] quadraticNbProbes = new int[NB_TESTS], doubleNbProbes = new int[NB_TESTS], linearNbProbes = new int[NB_TESTS];
		int[] percent = new int[NB_TESTS];
		final int step = MAX_PERCENT/NB_TESTS;
		
		for(int i=0 ; i<words.length ; i++)
			words[i] = is.nextWord();
		is.close();

		for(int i=0 ; i<NB_TESTS ; i++) {
			percent[i] = (i+1)*step;
			
			HashTableMap<String, String> linearHash = new HashTableMap<String, String>(CAPACITY);		
			HashTableMap<String, String> quadraticProbe = new QuadraticProbingHashTableMap<String, String>(CAPACITY);
			HashTableMap<String, String> doubleHash = new DoubleHashingHashTableMap<String, String>(CAPACITY, DOUBLE_HASHING_Q);
			
			System.out.println("=== Filling HashMapTable at " + percent[i] + "% ===");
			
			System.out.println("-- Linear Probing --");
			linearNbProbes[i] = fillTable(linearHash, words, percent[i]);
			System.out.println("-- Quadratic Probing --");
			quadraticNbProbes[i] = fillTable(quadraticProbe, words, percent[i]);
			System.out.println("-- Double Hashing --");
			doubleNbProbes[i] = fillTable(doubleHash, words, percent[i]);
		}
		
		plot = new Plot2D("Comparison of Quadratic Probe and Double Hashing", 800, 600);
		plot.addCurve(percent, linearNbProbes, Color.green);
		plot.addCurve(percent, quadraticNbProbes, Color.blue);
		plot.addCurve(percent, doubleNbProbes, Color.red);
		
		System.out.println("End.");
	}
	
	private static int fillTable(HashTableMap<String, String> hashMap, String[] words, int percentageOfFilling) {
		int nbProbes = 0;
		long timeElapsed = 0;
		final int nbWordsToFill = (percentageOfFilling*CAPACITY/100);

		for(int i=0 ; i<nbWordsToFill ; i++) {
			tic();
			
			try {
				hashMap.put(words[i], words[i]);
			}catch(InvalidKeyException e) {
				System.out.println(words[i] + " cannot be inserted into QuadraticProbingHashTableMap");
			}
			
			timeElapsed += toc();
			nbProbes += hashMap.getNbProbes();
		}
		
		
		for(int i=0 ; i<nbWordsToFill ; i++) {
			if(!words[i].equals(hashMap.get(words[i])))
				System.out.println("Problem : returned " + hashMap.get(words[i]) + " instead of "+ words[i]);
		}
			
		System.out.println("Time elapsed : " + timeElapsed + "ms");
		System.out.println("Probes : " + nbProbes);
		return nbProbes;
	}
	
	public static void tic() {
		start = System.currentTimeMillis();
	}
	
	public static long toc() {
		return System.currentTimeMillis() - start;
	}
}
