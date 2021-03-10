package parser.objectsanalysis;

import java.awt.Color;

import org.xml.sax.Attributes;

import world.Vector;

public class WorldObjectAnalysis {
	/**
	 * Default position vector
	 */
	public static final int DEFAULT_X = 0;
	public static final int DEFAULT_Y = 0;
	public static final int DEFAULT_Z = 0;
	
	/**
	 * Default color
	 */
	public static final int DEFAULT_R = 0;
	public static final int DEFAULT_G = 0;
	public static final int DEFAULT_B = 255;
	
	/**
	 * Default render parameters
	 */
	public static final int DEFAULT_PHONG = 10;
	public static final double DEFAULT_SPECULAR_REFLEXION = 1;
	public static final double DEFAULT_DIFFUSE_REFLEXION = 1;

	protected Vector position;
	protected Color color;
	protected int phong;
	protected double specularReflexion;
	protected double diffuseReflexion;
	
	/**
	 * Parse a double in the list of attribues.
	 * If this attribute is not found, the default value is returned
	 * @param attr
	 * @param qName
	 * @param defaultValue
	 * @return double parsed value 
	 */
	public static double parseDouble(Attributes attr, String qName, double defaultValue) {
		String rst = attr.getValue(qName);
		return (rst == null) ? defaultValue : Double.valueOf(rst);
	}
	
	/**
	 * Parse an integer in the list of attribues.
	 * If this attribute is not found, the default value is returned
	 * @param attr
	 * @param qName
	 * @param defaultValue
	 * @return integer parsed value 
	 */
	public static int parseInt(Attributes attr, String qName, int defaultValue) {
		String rst = attr.getValue(qName);
		return (rst == null) ? defaultValue : Integer.valueOf(rst);
	}
	
	/**
	 * Parse attribute for this WorldObject
	 * @param attr
	 */
	public void parseAttr(Attributes attr) {
		double x = parseDouble(attr, "x", DEFAULT_X);
		double y = parseDouble(attr, "y", DEFAULT_Y);
		double z = parseDouble(attr, "z", DEFAULT_Z);
		position = new Vector(x, y, z);

		int r = parseInt(attr, "r", DEFAULT_R);
		int g = parseInt(attr, "g", DEFAULT_G);
		int b = parseInt(attr, "b", DEFAULT_B);
		color = new Color(r, g, b);
		
		phong = parseInt(attr, "phong", DEFAULT_PHONG);
		specularReflexion = parseDouble(attr, "specular", DEFAULT_SPECULAR_REFLEXION);
		diffuseReflexion = parseDouble(attr, "diffuse", DEFAULT_DIFFUSE_REFLEXION);
	}	
	
	public Vector getVector() {
		return position;
	}

	public Color getColor() {
		return color;
	}

	public double getPhong() {
		return phong;
	}

	public double getSpecularReflexion() {
		return specularReflexion;
	}

	public double getDiffuseReflexion() {
		return diffuseReflexion;
	}
}
