package world;

import java.util.ArrayList;
import java.util.List;

public class World {
	private List<WorldObject> objects;
	private Camera camera;
	private AmbientLight ambientLight;
	private List<Light> lights;
	
	/**
	 * Create an empty world
	 */
	public World() {
		objects = new ArrayList<WorldObject>();
		lights = new ArrayList<Light>();
	}
	
	/**
	 * Add a object to the world
	 * @param o
	 */
	public void addObject(WorldObject o) {
		objects.add(o);
	}

	/**
	 * Add a light to the world
	 * @param o
	 */
	public void addLight(Light o) {
		lights.add(o);
	}
	
	/**
	 * Set the camera
	 * @param camera
	 */
	public void setCamera(Camera camera) {
		this.camera = camera;
	}
	
	/**
	 * Set the ambient light
	 * @param light
	 */
	public void setAmbientLight(AmbientLight light) {
		this.ambientLight = light;
	}

	public Camera getCamera() {
		return camera;
	}

	public AmbientLight getAmbientLight() {
		return ambientLight;
	}
	
	public List<WorldObject> getObjects() {
		return objects;
	}

	public List<Light> getLights() {
		return lights;
	}

	/**
	 * Check if the world is valid (has a light, a camera and at least one object)
	 * @return boolean
	 */
	public boolean valid() {
		return ambientLight != null && camera != null && objects.size() > 0;
	}
	
	/**
	 * Return a text represention of the World
	 * @return String
	 */
	public String toString() {
		String result = "Scene : \n" + camera + "\n" + ambientLight + "\n";
		for(Light l : lights)
			result += l + "\n";
		for(WorldObject o : objects)
			result += o + "\n";
		return result;
	}
}
