package renderer;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;

import main.Log;

import world.Camera;
import world.Vector;

public class Viewport {
	public static final double ALPHA = Math.PI/3; // Ouverture = 90°

	protected Camera camera;
	protected BufferedImage image;
	protected double dist; // distance from camera
	protected Vector origin; // bottom left of the viewport plan
	protected Vector u;
	protected Vector v;
	protected double width;
	protected double height;

	private JFrame frame = null;

	public Viewport(int imageWidth, int imageHeight, Vector cameraPos, Vector cameraDir) {
		image = new BufferedImage(imageWidth, imageHeight, BufferedImage.TYPE_INT_RGB); // XXX : Check type

		dist = 5;
		width = 2*dist*Math.tan(ALPHA/2);
		height = ((double) imageHeight/imageWidth)*width;

		Log.getInstance().debug("ViewPort : " + width + "x" + height);

		//origin = cameraDir.multiply(dist).add(cameraPos.minus(new Vector((double) width/2, (double) height/2, 0)));
		origin = new Vector(dist, -width/2, height/2);

		u = new Vector(0, 1, 0);
		v = new Vector(0, 0, 1);
	}

	public void setPixel(int x, int y, Color color) throws IllegalArgumentException {
		if(x < 0 && x >= image.getWidth() && y < 0 && y >= image.getHeight())
			throw new IllegalArgumentException();

		image.setRGB(x, y, color.getRGB());
		
		if(frame != null)
			frame.repaint();
	}

	public void saveImage(String filename, String formatName) throws IOException {
		ImageIO.write(image, formatName, new File(filename + "." + formatName));
	}

	/**
	 * Return the vector which as the camera position for origin and 
	 * go throught the pixel (x,y) of the viewport
	 * @param x
	 * @param y
	 * @return Vector
	 * @throws IllegalArgumentException
	 */
	public Vector getVector(int x, int y) throws IllegalArgumentException {
		if(x < 0 && x >= image.getWidth() && y < 0 && y >= image.getHeight())
			throw new IllegalArgumentException();

		return origin.add(u.multiply(translateCoordX(x))).add(v.multiply(translateCoordY(-y)));
	}

	private double translateCoordX(int x) {
		return (double) x*width /((double) image.getWidth());
	} 

	private double translateCoordY(int y) {
		return (double) y*height/((double) image.getWidth());
	}

	public int getWidth() {
		return image.getWidth();
	}

	public int getHeight() {
		return image.getHeight();
	}

	public double getRealWidth() {
		return width;
	}

	public double getRealHeight() {
		return height;
	}

	public Vector getOrigin() {
		return origin;
	}


	public void initFrame() {
		frame = new JFrame("Lazy Ray Tracer Output");
		frame.setSize(image.getWidth(), image.getHeight());
		frame.setContentPane(new JPanel() {
			private static final long serialVersionUID = 1L;

			public void paintComponent(Graphics g) 
			{ 
				super.paintComponent(g);
				g.drawImage(image, 0, 0, getWidth(), getHeight(), this); 
			}
		});
		frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		frame.setVisible(true); 
	}
}

