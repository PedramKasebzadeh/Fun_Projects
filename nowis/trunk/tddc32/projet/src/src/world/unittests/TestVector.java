package world.unittests;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

import world.Vector;


public class TestVector {
	private static final double EPSILON = 0.001;
	
	private Vector a;
	private Vector b;
	private Vector c;
	
	@Before
	public void construct() {
		a = new Vector(1, 0, 0);
		b = new Vector(1, 1, 1);
		c = new Vector(0, 5, 0);
	}
	
	@Test
	public void testGetNorm() {
		assertEquals("Norm of a unary vector", 1, a.getNorm(), EPSILON);
		assertEquals("Norm of " + b, Math.sqrt(3),b.getNorm(), EPSILON);
		assertEquals("Norm of " + c, 5, c.getNorm(), EPSILON);
	}
	
	@Test
	public void testScalarProduct() {
		assertEquals("Scalar product of orthogonal vectors", 0, a.scalarProduct(c), EPSILON);
		assertEquals("Scalar product of " + a + " " + b, 1, a.scalarProduct(b), EPSILON);
	}
	
	@Test
	public void testUnitize() {
		a.unitize();
		b.unitize();
		c.unitize();
		
		assertEquals("Unitize a unary vector", 1, a.getNorm(), EPSILON);
		assertEquals("Unitize " + b,           1, b.getNorm(), EPSILON);
		assertEquals("Unitize " + c,           1, c.getNorm(), EPSILON);
	}
}
