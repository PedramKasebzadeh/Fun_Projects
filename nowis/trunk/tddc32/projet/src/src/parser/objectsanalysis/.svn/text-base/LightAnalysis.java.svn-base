package parser.objectsanalysis;

import org.xml.sax.Attributes;

import parser.SaxAnalysis;
import parser.SaxMarkupAnalysis;
import world.Light;
import world.Vector;

public class LightAnalysis extends AmbientLightAnalysis implements SaxMarkupAnalysis {
	/**
	 * Default position vector
	 */
	public static final int DEFAULT_X = 0;
	public static final int DEFAULT_Y = 0;
	public static final int DEFAULT_Z = 0;
	
	protected Light light;

	public LightAnalysis(SaxAnalysis saxAnalysis) {
		super(saxAnalysis);
	}

	public void open(String qName, Attributes attr) {
		if (qName.equals("Light")) {
			double x = WorldObjectAnalysis.parseDouble(attr, "x", DEFAULT_X);
			double y = WorldObjectAnalysis.parseDouble(attr, "y", DEFAULT_Y);
			double z = WorldObjectAnalysis.parseDouble(attr, "z", DEFAULT_Z);
			light = new Light(new Vector(x, y, z), parseColor(attr));
		}
	}
	
	public void close(String qName) {
		if ("Light".equals(qName)) {
			saxAnalysis.readParsingResult(light);
		}
	}
}

