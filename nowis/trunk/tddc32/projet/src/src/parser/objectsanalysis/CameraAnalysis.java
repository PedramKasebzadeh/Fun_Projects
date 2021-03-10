package parser.objectsanalysis;

import org.xml.sax.Attributes;

import parser.SaxAnalysis;
import parser.SaxMarkupAnalysis;
import world.Camera;
import world.Vector;

public class CameraAnalysis implements SaxMarkupAnalysis {
	/**
	 * Default position vector
	 */
	public static final int DEFAULT_X = 0;
	public static final int DEFAULT_Y = 0;
	public static final int DEFAULT_Z = 0;
	
	/**
	 * Default direction vector
	 */
	public static final int DEFAULT_DX = 1;
	public static final int DEFAULT_DY = 0;
	public static final int DEFAULT_DZ = 0;
	
	/**
	 * Default image settings
	 */
	public static final int DEFAULT_WIDTH = 640;
	public static final int DEFAULT_HEIGHT = 480;
	
	private SaxAnalysis saxAnalysis;
	private Camera camera;

	public CameraAnalysis(SaxAnalysis saxAnalysis) {
		this.saxAnalysis = saxAnalysis;
	}

	public void open(String qName, Attributes attr) {
		if (qName.equals("Camera")) {
			double x = WorldObjectAnalysis.parseDouble(attr, "x", DEFAULT_X);
			double y = WorldObjectAnalysis.parseDouble(attr, "y", DEFAULT_Y);
			double z = WorldObjectAnalysis.parseDouble(attr, "z", DEFAULT_Z);
			double dx = WorldObjectAnalysis.parseDouble(attr, "dx", DEFAULT_DX);
			double dy = WorldObjectAnalysis.parseDouble(attr, "dy", DEFAULT_DY);
			double dz = WorldObjectAnalysis.parseDouble(attr, "dz", DEFAULT_DZ);
			int width = WorldObjectAnalysis.parseInt(attr, "width", DEFAULT_WIDTH);
			int height = WorldObjectAnalysis.parseInt(attr, "height", DEFAULT_HEIGHT);
			
			/** XXX : Forcing to default before improving ViewPort **/
			x = DEFAULT_X;
			y = DEFAULT_Y;
			z = DEFAULT_Z;
			dx = DEFAULT_DX;
			dy = DEFAULT_DY;
			dz = DEFAULT_DZ;
			camera = new Camera(new Vector(x, y, z), new Vector(dx, dy, dz), width, height);
		}
	}
	
	public void close(String qName) {
		if ("Camera".equals(qName)) {
			saxAnalysis.readParsingResult(camera);
		}
	}
}
