package world;

import java.awt.Color;

import renderer.Intersection;
import renderer.Ray;
import renderer.NoIntersection;

/**
 * Generic abstract world object
 * Describe general parameters of world objects
 * All world object extends this class
 */
public abstract class WorldObject {
	/**
	 * Default color of object (blue)
	 */
	public static final Color DEFAULT_COLOR = Color.blue;
	/**
	 * Default phong coefficient
	 */
	public static final int DEFAULT_PHONG = 1;
	/**
	 * Default specular reflexion coefficient
	 */
	public static final double DEFAULT_SPECULAR_REFLEXION = 0.2;
	/**
	 * Default diffuse reflexion coefficient
	 */
	public static final double DEFAULT_DIFFUSE_REFLEXION = 0.2;
	
	protected Vector position;
	protected Color color;
	protected int phong;
	protected double specularReflexion;
	protected double diffuseReflexion;
	
	/**
	 * Create an object at given position with default parameters
	 * @param pos Object position
	 * @see DEFAULT_COLOR
	 * @see DEFAULT_PHONG
	 * @see DEFAULT_SPECULAR_REFLEXION
	 * @see DEFAULT_DIFFUSE_REFLEXION
	 */
	protected WorldObject(Vector pos) {
		this(pos, DEFAULT_COLOR, DEFAULT_PHONG, DEFAULT_SPECULAR_REFLEXION, DEFAULT_DIFFUSE_REFLEXION);
	}
	
	/**
	 * Create an object at given parameters
	 * @param pos Object position
	 * @param color
	 * @param phong
	 * @param specularReflexion
	 * @param diffuseReflexion
	 */
	protected WorldObject(Vector pos, Color color, int phong,
						  double specularReflexion, double diffuseReflexion) {
		this.position = pos;
		this.color = color;
		this.phong = phong;
		this.specularReflexion = specularReflexion;
		this.diffuseReflexion = diffuseReflexion;
	}

	/**
	 * TODO
	 * @param ray
	 * @return an Intersection
	 * @throws NoIntersection
	 */
	public abstract Intersection intersect(Ray ray) throws NoIntersection;
	
	/**
	 * Translate object with given vector 
	 * @param vector
	 */
	public void translate(Vector vector) {
		position.translate(vector);
	}

	public Vector getPosition() {
		return position;
	}

	public void setPosition(Vector position) {
		this.position = position;
	}

	public Color getColor() {
		return color;
	}

	public void setColor(Color color) {
		this.color = color;
	}

	public int getPhong() {
		return phong;
	}

	public void setPhong(int phong) {
		this.phong = phong;
	}

	public double getSpecularReflexion() {
		return specularReflexion;
	}

	public void setSpecularReflexion(double specularReflexion) {
		this.specularReflexion = specularReflexion;
	}

	public double getDiffuseReflexion() {
		return diffuseReflexion;
	}

	public void setDiffuseReflexion(double diffuseReflexion) {
		this.diffuseReflexion = diffuseReflexion;
	}
	
	/**
	 * Return a text represention of the object
	 * @return String
	 */
	public String toString() {
		return "(pos" + position + ";" + color + ";" + phong + ";" + specularReflexion + ";" + diffuseReflexion + ")";
	}
}
