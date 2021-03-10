package parser.objectsanalysis;

import org.xml.sax.Attributes;

import parser.SaxAnalysis;
import parser.SaxMarkupAnalysis;
import world.Cube;
import world.Vector;

public class CubeAnalysis extends WorldObjectAnalysis implements SaxMarkupAnalysis {
	public static final double DEFAULT_SIZE = 5;
	
	private SaxAnalysis saxAnalysis;
	private Cube cube;

	public CubeAnalysis(SaxAnalysis saxAnalysis) {
		this.saxAnalysis = saxAnalysis;
	}

	public void open(String qName, Attributes attr) {
		if (qName.equals("Cube")) {
			parseAttr(attr);
			double size = parseDouble(attr, "size", DEFAULT_SIZE);
			cube = new Cube(position, new Vector(0, 0, 0), size, color, phong, specularReflexion, diffuseReflexion);
		}
	}
	
	public void close(String qName) {
		if ("Cube".equals(qName)) {
			saxAnalysis.readParsingResult(cube);
		}
	}
}
