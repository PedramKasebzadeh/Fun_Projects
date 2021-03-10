package world.unittests;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import renderer.NoIntersection;
import renderer.Ray;

import world.Cube;
import world.Vector;


public class TestCube {	
	private Cube cube;
	private Ray rayIn;
	private Ray rayOut;
	
	@Before
	public void construct() {
		cube = new Cube(new Vector(10, 0, 0), 5);
		rayIn = new Ray(new Vector(0, 0, 0), new Vector(1, 0, 0));
		rayOut = new Ray(new Vector(0, 0, 0), new Vector(10, 6, 0));
	}
	
	@Test
	public void testIntersect() {
		try {
			cube.intersect(rayIn);
		} catch(NoIntersection e) {
			fail("The cube must intersect with this ray.");
		}
		
		try {
			cube.intersect(rayOut);
			fail("The cube must not intersect with this ray.");
		} catch(NoIntersection e) {
		}
	}
}
