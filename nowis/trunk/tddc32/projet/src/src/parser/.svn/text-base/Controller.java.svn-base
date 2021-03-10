package parser;

import main.Log;
import world.AmbientLight;
import world.Camera;
import world.Light;
import world.World;
import world.WorldObject;

public class Controller {
	private static Controller instance = null;
	
	private World world = null;

	private Controller() {}
	
	public static Controller getInstance() {
		if (instance == null) {
			instance = new Controller();
		}
		return instance;
	}
	
	public void handleObject(Object o) throws InvalidSceneXMLFile {
		if(o instanceof World) {
			if(world != null) 
				throw new InvalidSceneXMLFile();
			
			world = (World) o;
			return;
		}
		
		if(world == null)
			throw new InvalidSceneXMLFile();
		
		if(o instanceof WorldObject) {
			Log.getInstance().debug("New world object : " + o);
			world.addObject((WorldObject) o);
		} else if(o instanceof Camera) {
			Log.getInstance().debug("New camera : " + o);
			world.setCamera((Camera) o);
		} else if(o instanceof Light) {
			Log.getInstance().debug("New light : " + o);
			world.addLight((Light) o);
		} else if(o instanceof AmbientLight) {
			Log.getInstance().debug("New ambient light : " + o);
			world.setAmbientLight((AmbientLight) o);
		} else {
			Log.getInstance().println("Unespected object : " + o);
			System.exit(1);
		}
	}
	
	public World getWorld() {
		return world;
	}
}
