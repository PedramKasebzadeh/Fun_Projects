package world;

import renderer.Viewport;

public class Camera {
	private Vector pos;
	private Vector direction;
	private Viewport vp;
	
	public Camera(Vector pos, Vector direction, int width, int height) {
		this.pos = pos;
		this.direction = direction;
		vp = new Viewport(width, height, pos, direction);
	}

	public Vector getPos() {
		return pos;
	}
	
	public Vector getDirection() {
		return direction;
	}
	
	public Viewport getViewPort() {
		return vp;
	}
	
	public String toString() {
		return "Camera [pos" + pos + ", dir" + direction + "]";
	}
}
