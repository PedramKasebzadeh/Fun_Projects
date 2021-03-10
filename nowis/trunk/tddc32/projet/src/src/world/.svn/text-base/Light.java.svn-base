package world;

import java.awt.Color;

public class Light extends AmbientLight {
	public Vector position;
	
	public Light(Color color) {
		this(new Vector(0, 0, 0), color);
	}
	
	public Light(Vector position, Color color) {
		super(color);
		this.position = position;
	}

	public Vector getPosition() {
		return position;
	}
	
	public String toString() {
		return "Light [" + position + ";" + color + "]";
	}
}
