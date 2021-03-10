package world;

import java.awt.Color;

public class AmbientLight {
	protected Color color;
	
	public AmbientLight(Color color) {
		this.color = color;
	}

	public Color getColor() {
		return color;
	}

	public void setColor(Color color) {
		this.color = color;
	}
	
	public String toString() {
		return "AmbiantLight [" + color + "]";
	}
}
