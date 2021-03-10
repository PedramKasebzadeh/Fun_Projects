package renderer.unittests;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import renderer.Intersection;
import renderer.NoIntersection;
import renderer.Ray;
import world.Sphere;
import world.Vector;
import world.WorldObject;


public class TestRay {
	private static final double EPSILON = 0.001;
	
	private Ray ray;
	private List<WorldObject> objects;
	private Sphere s;
	
	@Before
	public void contruct() {
		ray = new Ray(new Vector(0, 0, 0), new Vector(1, 0, 0));
		
		objects = new ArrayList<WorldObject>(4);
		objects.add(new Sphere(new Vector(2, 1, 0), 0.5));
		s = new Sphere(new Vector(2, 0, 0), 1);
		objects.add(s);
		objects.add(new Sphere(new Vector(-1, 0, 0), 0.5));
		objects.add(new Sphere(new Vector(4, 10, 0), 5));
	}
	
	@Test
	public void testTrace() throws NoIntersection {
		Intersection i = ray.trace(objects);
		assertEquals("Distance", 1, i.getDistance(), EPSILON);
		assertEquals("Sphere", s.toString(), i.getWorldObject().toString());
		
	}
}
