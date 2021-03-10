package parser.objectsanalysis;

import org.xml.sax.Attributes;

import parser.SaxAnalysis;
import parser.SaxMarkupAnalysis;
import world.Sphere;

public class SphereAnalysis extends WorldObjectAnalysis implements SaxMarkupAnalysis {
	public static final double DEFAULT_RADIUS = 5;
	
	private SaxAnalysis saxAnalysis;
	private Sphere sphere;

	public SphereAnalysis(SaxAnalysis saxAnalysis) {
		this.saxAnalysis = saxAnalysis;
	}

	public void open(String qName, Attributes attr) {
		if (qName.equals("Sphere")) {
			parseAttr(attr);
			double radius = parseDouble(attr, "radius", DEFAULT_RADIUS);
			sphere = new Sphere(position, radius, color, phong, specularReflexion, diffuseReflexion);
		}
	}
	
	public void close(String qName) {
		if ("Sphere".equals(qName)) {
			saxAnalysis.readParsingResult(sphere);
		}
	}
}
