package renderer;

import java.awt.Color;
import java.io.IOException;

import world.Light;
import world.Vector;
import world.World;
import world.WorldObject;

public class Renderer implements Runnable {
	private static final long serialVersionUID = 1L;
	
	public static final Color backgroundColor = Color.BLACK;
	
	public String filename;
	public String formatName;
	public World w;
	public int minX;
	public int maxX;

	public static final int MAX_LEVEL = 4;

	/**
	 * Create a thread of the Renderer.
	 * It will fill the image from minX (included) to max (excluded)
	 * @param filename
	 * @param formatName
	 * @param w
	 * @param minX
	 * @param maxX
	 */
	public Renderer(String filename, String formatName, World w, int minX, int maxX) {
		this.filename = filename;
		this.formatName = formatName;
		this.w = w;
		this.minX = minX;
		this.maxX = maxX;
	}

	/**
	 * Main entrance of renderer threads
	 * Calculate color of pixels from columns minX to maxX
	 */
	public void run() {
		Viewport vp = w.getCamera().getViewPort();

		for(int x=minX ; x<maxX ; x++) {
			for(int y=0 ; y<vp.getHeight() ; y++) {
				Ray ray = new Ray(w.getCamera().getPos(), vp.getVector(x, y));
				//Log.getInstance().debug("Throwing ray : " + ray);
				try {
					Color c = cast(ray, 0);
					vp.setPixel(x, y, c);
				} catch (NoIntersection e) {
					vp.setPixel(x, y, backgroundColor);
				}
			}
		}
	}

	/**
	 * Cast the ray an calculate the color.
	 * This method stop the recursion at a maximum setted level
	 * @param ray
	 * @param level
	 * @return pixel color
	 * @throws NoIntersection
	 */
	private Color cast(Ray ray, int level) throws NoIntersection {
		if(level > MAX_LEVEL)
			return backgroundColor;
		return calculateColor(ray.trace(w.getObjects()), ray, ++level);
	}

	/**
	 * Calculate the color of a pixel recursively given an intersection and a ray
	 * @param inter
	 * @param ray
	 * @param level
	 * @return Color
	 * @throws NoIntersection
	 */
	private Color calculateColor(Intersection inter, Ray ray, int level) throws NoIntersection {
		WorldObject o = inter.getWorldObject();
		Color objectColor = o.getColor();
		double kd = o.getDiffuseReflexion();
		double ks = o.getSpecularReflexion();
		int phong = o.getPhong();

		Color lightColor = w.getAmbientLight().getColor();
		
		/** Recursively calculate the color of the reflected ray **/
		Color reflectColor;
		try {
			reflectColor = cast(reflectRay(ray, inter), level);
		} catch(NoIntersection e) {
			reflectColor = backgroundColor;
		}

		/** ambient light **/
		double rl = ((double) lightColor.getRed())/255f;
		double gl = ((double) lightColor.getGreen())/255f;
		double bl = ((double) lightColor.getBlue())/255f;

		/** object **/
		double ro = ((double) objectColor.getRed())/255f;
		double go = ((double) objectColor.getGreen())/255f;
		double bo = ((double) objectColor.getBlue())/255f;
		Vector objectC = new Vector(ro, go, bo);

		/** reflexion **/
		double rr = ((double) reflectColor.getRed())/255f;
		double gr = ((double) reflectColor.getGreen())/255f;
		double br = ((double) reflectColor.getBlue())/255f;

		/** others lights **/
		Vector lightsC = calculateLights(inter, ray, kd, ks, phong, objectC);
		
		// finally adds up to get the pixel color
		float red = (float) (kd*rl*ro + lightsC.getX() + ks*rr);
		float green = (float) (kd*gl*go + lightsC.getY() + ks*gr);
		float blue = (float) (kd*bl*bo + lightsC.getZ() + ks*br);

		return new Color(red > 1f ? 1 : red, green > 1f ? 1 : green, blue > 1f ? 1 : blue);
	}

	/**
	 * Calculate the color given by the lights (others than the ambient one)
	 * @param inter
	 * @param ray
	 * @param kd
	 * @param objectC
	 * @return Vector of the colors (R, G, B)
	 */
	private Vector calculateLights(Intersection inter, Ray ray, double kd, double ks, int phong, Vector objectC) {
		Vector sumPhong = new Vector(0, 0, 0);
		
		// color = kd * sum(normal.L * intensity)
		// kd : diffuse cofficient
		// normal : normal vector to the surface
		// L : vector from the intersection to the light
		// intensity of the light
		double rLights = 0;
		double gLights = 0;
		double bLights = 0;
		for(Light l : w.getLights()) {
			Vector interPos = ray.getDirection().multiply(inter.getDistance()).add(ray.getOrigin());
			Vector lightDir = l.getPosition().minus(interPos);
			try {
				if(inter.getNormal().scalarProduct(lightDir) >= 0) {
					Ray lightRay = new Ray(interPos, lightDir);
					Intersection i = lightRay.trace(w.getObjects());
					if(i.getDistance() < lightDir.getNorm())
						throw new NoIntersection();
				}
			} catch(NoIntersection e) {
				double d = Math.abs(inter.getNormal().scalarProduct(lightDir));
				double r = ((double) l.getColor().getRed())/255f;
				double g = ((double) l.getColor().getGreen())/255f;
				double b = ((double) l.getColor().getBlue())/255f;
				rLights += d*r;
				gLights += d*g;
				bLights += d*b;
				
				sumPhong = sumPhong.add(calculatePhong(l, inter, ray, ks, objectC, phong));
			}
		}
		
		return new Vector(rLights*kd*objectC.getX() + sumPhong.getX(), 
						  gLights*kd*objectC.getY() + sumPhong.getY(), 
						  bLights*kd*objectC.getZ() + sumPhong.getZ());
	}

	/**
	 * Calculate the color of the diffuse reflexion with phong
	 * @param inter
	 * @param ray
	 * @param ks
	 * @param objectC
	 * @param phong
	 * @return Color
	 */
	private Vector calculatePhong(Light l, Intersection inter, Ray ray, double ks, Vector objectC, int phong) {
		Vector origin = ray.getDirection().multiply(inter.getDistance()).add(ray.getOrigin());
		
		Vector bissect = ray.getDirection().multiply(-1);
		Vector lightDir = l.getPosition().minus(origin);
		lightDir.unitize();
		Vector transformation = lightDir.minus(bissect).multiply(0.5);
		bissect = bissect.add(transformation);

		double d = Math.pow(inter.getNormal().scalarProduct(bissect), phong);
		double r = ((double) l.getColor().getRed())/255f;
		double g = ((double) l.getColor().getGreen())/255f;
		double b = ((double) l.getColor().getBlue())/255f;

		return new Vector(ks*d*r*objectC.getX(), ks*d*g*objectC.getY(), ks*d*b*objectC.getZ());
	}
	
	/**
	 * Calculate the origin and the direction of the reflect ray (Specular reflection)
	 * Origin : position of the intersection
	 * Direction : the direction of incoming light (the incident ray), and the direction of outgoing light reflected (the reflected ray)
	 *             make the same angle with respect to the surface normal, thus the angle of incidence equals the angle of reflection
	 * @param ray
	 * @param inter
	 * @return reflected ray
	 */
	private static Ray reflectRay(Ray ray, Intersection inter) {
		Vector origin = ray.getDirection().multiply(inter.getDistance()).add(ray.getOrigin());
		Vector direction = ray.getDirection().multiply(-1); 
		Vector normal = inter.getNormal();
		Vector transformation = normal.multiply(normal.scalarProduct(direction)).minus(direction);
		direction = direction.add(transformation).add(transformation);

		return new Ray(origin, direction);
	}
	/**
	 * Launch the threads
	 * @param filename
	 * @param formatName
	 * @param w
	 * @param nbThreads
	 * @throws IOException
	 */
	public static void Render(String filename, String formatName, World w, int nbThreads) throws IOException {
		Thread[] t = new Thread[nbThreads];
		Viewport vp = w.getCamera().getViewPort();
		int nbColumns = vp.getWidth() / nbThreads;
		int rest =  vp.getWidth() % nbThreads;
		
		for(int i=0 ; i<nbThreads ; i++) {
			t[i] = new Thread(new Renderer(filename, formatName, w, i*nbColumns, (i+1)*nbColumns));
			t[i].start();
		}
		
		for(int i=0 ; i<nbThreads ; i++) {
			try {
				t[i].join();
			} catch (InterruptedException e) {}
		}
		
		if(rest > 0) {
			Thread restT = new Thread(new Renderer(filename, formatName, w, nbThreads*nbColumns, nbThreads*nbColumns + rest));
			restT.run();
			try {
				restT.join();
			} catch (InterruptedException e) {}
		}
		
		vp.saveImage(filename, formatName);
	}
}
