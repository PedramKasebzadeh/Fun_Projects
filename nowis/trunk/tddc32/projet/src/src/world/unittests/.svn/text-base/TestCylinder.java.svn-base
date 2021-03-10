package world.unittests;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import renderer.NoIntersection;
import renderer.Ray;

import world.Cylinder;
import world.Vector;


public class TestCylinder {	
	private Cylinder cylinder;
	private Ray rayIn;
	private Ray rayOut;
	
	@Before
	public void construct() {
		cylinder = new Cylinder(new Vector(10, 0, 0), 5, 5);
		rayIn = new Ray(new Vector(0, 0, 0), new Vector(1, 0, 0));
		rayOut = new Ray(new Vector(0, 0, 0), new Vector(10, 6, 0));
	}
	
	@Test
	public void testIntersect() {
		try {
			cylinder.intersect(rayIn);
		} catch(NoIntersection e) {
			fail("The cylinder must intersect with this ray.");
		}
		
		try {
			cylinder.intersect(rayOut);
			fail("The cylinder must not intersect with this ray.");
		} catch(NoIntersection e) {
		}
	}
}
