package parser.objectsanalysis;

import org.xml.sax.Attributes;

import parser.SaxAnalysis;
import parser.SaxMarkupAnalysis;
import world.Cylinder;
import world.Vector;

public class CylinderAnalysis extends WorldObjectAnalysis implements SaxMarkupAnalysis {
	public static final double DEFAULT_RADIUS = 2;
	public static final double DEFAULT_HEIGHT = 10;
	
	private SaxAnalysis saxAnalysis;
	private Cylinder cylinder;

	public CylinderAnalysis(SaxAnalysis saxAnalysis) {
		this.saxAnalysis = saxAnalysis;
	}

	public void open(String qName, Attributes attr) {
		if (qName.equals("Cylinder")) {
			parseAttr(attr);
			double radius = parseDouble(attr, "radius", DEFAULT_RADIUS);
			double height = parseDouble(attr, "height", DEFAULT_HEIGHT);
			cylinder = new Cylinder(position, new Vector(0, 0, 0), radius, height, color, phong, specularReflexion, diffuseReflexion);
		}
	}
	
	public void close(String qName) {
		if ("Cylinder".equals(qName)) {
			saxAnalysis.readParsingResult(cylinder);
		}
	}
}
