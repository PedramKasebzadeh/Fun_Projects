package renderer;

import java.util.List;

import world.Vector;
import world.WorldObject;

public class Ray {
	protected final Vector origin;
	protected final Vector direction; 
	
	public Ray(Vector origin, Vector direction) {
		this.origin = origin;
		this.direction = direction;
		this.direction.unitize();
	}
	
	public Intersection trace(List<WorldObject> objects) throws NoIntersection {
		boolean inter = false;
		
		Intersection closest = Intersection.INFINITE_INTERSECTION;
		for(WorldObject o : objects) {
			try {
				Intersection i = o.intersect(this);
				if(Math.abs(i.getDistance()) < Math.abs(closest.getDistance())) {
					inter = true;
					closest = i;
				}
			} catch(NoIntersection e) {}
		}
		
		if(!inter)
			throw new NoIntersection();
		
		return closest;
	}

	public Vector getOrigin() {
		return origin;
	}

	public Vector getDirection() {
		return direction;
	}
	
	public String toString() {
		return "Ray [pos" + origin + " - dir" + direction +"]";
	}
}
