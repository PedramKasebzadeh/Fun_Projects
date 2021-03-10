package world;

import java.awt.Color;

import renderer.Intersection;
import renderer.NoIntersection;
import renderer.Ray;

public class Cylinder extends RotableObject {
	private double radius;
	private double height;

	/**
	 * Construct a cylinder at position pos and with given radius and height.
	 * Other specification are default setted by WorldObject.
	 * @param pos Cylinder position (center)
	 * @param radius Cylinder radius
	 * @param height Cylinder height
	 * @see WorldObject
	 */
	public Cylinder(Vector pos, double radius, double height) {
		super(pos);
		this.radius = radius;
		this.height = height;
	}

	/**
	 * Construct a cylinder with given parameters
	 * @param pos Cylinder position (center)
	 * @param rot Cube vector rotation
	 * @param radius Cylinder radius
	 * @param height Cylinder height
	 * @param color Cylinder color
	 * @param phong Cylinder phong coefficient (control amount of phong effect)
	 * @param specularReflexion specular reflexion coefficient
	 * @param diffuseReflexion diffuse reflexion coefficient
	 */
	public Cylinder(Vector pos, Vector rot, double radius, double height, Color color, int phong,
			  double specularReflexion, double diffuseReflexion) {
		super(pos, rot, color, phong, specularReflexion, diffuseReflexion);
		this.radius = radius;
		this.height = height;
	}

	/**
	 * @return The radius of this cylinder
	 */
	public double getRadius() {
		return radius;
	}

	/**
	 * Change the radius of the cylinder 
	 * @param radius
	 */
	public void setRadius(double radius) {
		this.radius = radius;
	}

	/**
	 * @return The height of this cylinder
	 */
	public double getHeight() {
		return height;
	}

	/**
	 * Change the height of the cylinder
	 * @param height
	 */
	public void setHeight(double height) {
		this.height = height;
	}
	
	/**
	 * Return a text represention of the Cylinder
	 * @return String
	 */
	public String toString() {
		return "Cylinder " + super.toString() + " [" + radius + ";" + height + "]";
	}

	public Intersection intersect(Ray ray) throws NoIntersection {
		// XXX : TODO
		return new Sphere(position, radius).intersect(ray);
	}
}
