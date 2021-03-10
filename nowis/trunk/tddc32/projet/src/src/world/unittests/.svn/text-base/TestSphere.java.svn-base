package world.unittests;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import renderer.NoIntersection;
import renderer.Ray;

import world.Sphere;
import world.Vector;


public class TestSphere {	
	private Sphere sphere;
	private Ray rayIn;
	private Ray rayOut;
	
	@Before
	public void construct() {
		sphere = new Sphere(new Vector(10, 0, 0), 5);
		rayIn = new Ray(new Vector(0, 0, 0), new Vector(1, 0, 0));
		rayOut = new Ray(new Vector(0, 0, 0), new Vector(10, 6, 0));
	}
	
	@Test
	public void testIntersect() {
		try {
			sphere.intersect(rayIn);
		} catch(NoIntersection e) {
			fail("The sphere must intersect with this ray.");
		}
		
		try {
			sphere.intersect(rayOut);
			fail("The sphere must not intersect with this ray.");
		} catch(NoIntersection e) {
		}
	}
}
