package world;

import java.awt.Color;

import renderer.Intersection;
import renderer.NoIntersection;
import renderer.Ray;

public class Cube extends RotableObject {
	private double size;

	/**
	 * Construct a cube at position pos and with given side size.
	 * Other specification are default setted by WorldObject.
	 * @param pos Cube position (center)
	 * @param size Cube side size
	 * @see WorldObject
	 */
	public Cube(Vector pos, double size) {
		super(pos);
		this.size = size;
	}

	/**
	 * Construct a cube with given parameters
	 * @param pos Cube position (center)
	 * @param rot Cube vector rotation
	 * @param size Cube side size
	 * @param color Cube color
	 * @param phong Cube phong coefficient (control amount of phong effect)
	 * @param specularReflexion specular reflexion coefficient
	 * @param diffuseReflexion diffuse reflexion coefficient
	 */
	public Cube(Vector pos, Vector rot, double size, Color color, int phong,
			double specularReflexion, double diffuseReflexion) {
		super(pos, rot, color, phong, specularReflexion, diffuseReflexion);
		this.size = size;
	}

	/**
	 * @return The side size of this cube
	 */
	public double getSize() {
		return size;
	}

	/**
	 * Change the side size of the cube
	 * @param size
	 */
	public void setSize(double size) {
		this.size = size;
	}

	/**
	 * Return a text represention of the Cube
	 * @return String
	 */
	public String toString() {
		return "Cube " + super.toString() + " [" + size + "]";
	}

	/*
	public Intersection intersect(Ray ray) throws NoIntersection {
		double tmin, tmax;
		double tymin, tymax, tzmin, tzmax; 
		double flag = 1.0; 
		
		Vector b = position.add(new Vector(size, size, size));
		
		if(ray.getDirection().getX() >= 0) {
			tmin = (position.getX() - ray.getOrigin().getX()) / ray.getDirection().getX();
			tmax = (b.getX() - ray.getOrigin().getX()) / ray.getDirection().getX();
		} else {
			tmin = (b.getX() - ray.getOrigin().getX()) / ray.getDirection().getX();
			tmax = (position.getX() - ray.getOrigin().getX()) / ray.getDirection().getX();
		}
		
		if(ray.getDirection().getY() >= 0) {
			tymin = (position.getY() - ray.getOrigin().getY()) / ray.getDirection().getY();
			tymax = (b.getY() - ray.getOrigin().getY()) / ray.getDirection().getY();
		} else {
			tymin = (b.getY() - ray.getOrigin().getY()) / ray.getDirection().getY();
			tymax = (position.getY() - ray.getOrigin().getY()) / ray.getDirection().getY();
		}

		if(tmin > tymax || tymin > tmax)
			flag = -1.0; 
		if(tymin > tmin)
			tmin = tymin; 
		if(tymax < tmax)
			tmax = tymax; 

		if(ray.getDirection().getZ() >= 0) {
			tzmin = (position.getZ() - ray.getOrigin().getZ()) / ray.getDirection().getZ();
			tzmax = (b.getZ() - ray.getOrigin().getZ()) / ray.getDirection().getZ();
		} else {
			tzmin = (b.getZ() - ray.getOrigin().getZ()) / ray.getDirection().getZ();
			tzmax = (position.getZ() - ray.getOrigin().getZ()) / ray.getDirection().getZ();
		}
		
		if(tmin > tzmax || tzmin > tmax)
			flag = -1.0; 
		if(tzmin > tmin)
			tmin = tzmin; 
		if(tzmax < tmax)
			tmax = tzmax; 

		if(flag <= 0)
			throw new NoIntersection();
		
		return new Intersection(tmin, null, this);
	}
	*/
	

	public Intersection intersect(Ray ray) throws NoIntersection {
		// XXX : TODO
		return new Sphere(position, size/2).intersect(ray);
	}
}

