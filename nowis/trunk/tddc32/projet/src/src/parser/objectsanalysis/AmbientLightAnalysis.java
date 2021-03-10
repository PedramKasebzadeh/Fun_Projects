package parser.objectsanalysis;

import java.awt.Color;

import org.xml.sax.Attributes;

import parser.SaxAnalysis;
import parser.SaxMarkupAnalysis;
import world.AmbientLight;

public class AmbientLightAnalysis implements SaxMarkupAnalysis {
	/**
	 * Default color
	 */
	public static final int DEFAULT_R = 0;
	public static final int DEFAULT_G = 0;
	public static final int DEFAULT_B = 255;
	
	protected SaxAnalysis saxAnalysis;
	private AmbientLight light;

	public AmbientLightAnalysis(SaxAnalysis saxAnalysis) {
		this.saxAnalysis = saxAnalysis;
	}

	public void open(String qName, Attributes attr) {
		if (qName.equals("AmbientLight")) {
			light = new AmbientLight(parseColor(attr));
		}
	}
	
	public void close(String qName) {
		if ("AmbientLight".equals(qName)) {
			saxAnalysis.readParsingResult(light);
		}
	}

	public static Color parseColor(Attributes attr) {
		int r = WorldObjectAnalysis.parseInt(attr, "r", DEFAULT_R);
		int g = WorldObjectAnalysis.parseInt(attr, "g", DEFAULT_G);
		int b = WorldObjectAnalysis.parseInt(attr, "b", DEFAULT_B);
		return new Color(r, g, b);
	}
}
