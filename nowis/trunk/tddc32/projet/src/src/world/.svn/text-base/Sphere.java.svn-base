package world;

import java.awt.Color;

import renderer.Intersection;
import renderer.NoIntersection;
import renderer.Ray;

/**
 * Sphere Object
 */
public class Sphere extends WorldObject {
	private double radius;
	
	/**
	 * Construct a sphere at position pos and with given radius.
	 * Other specification are default setted by WorldObject.
	 * @param pos Sphere position (center)
	 * @param radius Sphere radius
	 * @see WorldObject
	 */
	public Sphere(Vector pos, double radius) {
		super(pos);
		this.radius = radius;
	}
	
	/**
	 * Construct a sphere with given parameters
	 * @param pos Sphere position (center)
	 * @param radius Sphere radius
	 * @param color Sphere color
	 * @param phong Sphere phong coefficient (control amount of phong effect)
	 * @param specularReflexion specular reflexion coefficient
	 * @param diffuseReflexion diffuse reflexion coefficient
	 */
	public Sphere(Vector pos, double radius, Color color, int phong,
			  double specularReflexion, double diffuseReflexion) {
		super(pos, color, phong, specularReflexion, diffuseReflexion);
		this.radius = radius;
	}

	/**
	 * @return The radius of this sphere
	 */
	public double getRadius() {
		return radius;
	}

	/**
	 * Change the radius of the sphere
	 * @param radius
	 */
	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	/**
	 * Return a text represention of the Sphere
	 * @return String
	 */
	public String toString() {
		return "Sphere " + super.toString() + " [" + radius + "]";
	}

	public Intersection intersect(Ray ray) throws NoIntersection {
		Vector dst = ray.getOrigin().minus(this.position);
		double B = dst.scalarProduct(ray.getDirection());
		double C = dst.scalarProduct(dst) - this.radius*this.radius;
		double D = B*B - C;

		double dist = -B - Math.sqrt(D);
		if(D <= 0 || dist <= 0)
			throw new NoIntersection();
		
		return new Intersection(dist, ray.getDirection().multiply(dist).add(ray.getOrigin()).minus(position), this);
	}
}
