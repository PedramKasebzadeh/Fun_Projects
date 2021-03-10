package renderer;

import world.Vector;
import world.WorldObject;

public class Intersection {
	public static final Intersection INFINITE_INTERSECTION = new Intersection(Double.POSITIVE_INFINITY, null, null);
	
	protected final double distance;
	protected final Vector normal;
	protected final WorldObject o;
	
	public Intersection(double distance, Vector normal, WorldObject o) {
		this.distance = distance;
		this.normal = normal;
		if(normal != null)
			this.normal.unitize();
		this.o = o;
	}

	public double getDistance() {
		return distance;
	}

	public Vector getNormal() {
		return normal;
	}

	public WorldObject getWorldObject() {
		return o;
	}
}
