package world;

import java.awt.Color;

public abstract class RotableObject extends WorldObject {
	Vector rot;
	
	/**
	 * Create an object at given position with default parameters
	 * @param pos Object position
	 * @see DEFAULT_COLOR
	 * @see DEFAULT_PHONG
	 * @see DEFAULT_SPECULAR_REFLEXION
	 * @see DEFAULT_DIFFUSE_REFLEXION
	 */
	protected RotableObject(Vector pos) {
		super(pos);
		this.rot = new Vector(0, 0, 0);
	}
	
	/**
	 * Create an object at given parameters
	 * @param pos Object position
	 * @param color
	 * @param phong
	 * @param specularReflexion
	 * @param diffuseReflexion
	 */
	protected RotableObject(Vector pos, Vector rot, Color color, int phong,
						  double specularReflexion, double diffuseReflexion) {
		super(pos, color, phong, specularReflexion, diffuseReflexion);
		this.rot = rot;
	}


	public void rotate(double angleX, double angleY, double angleZ) {
    	double x = rot.getX();
    	double y = rot.getY();
    	double z = rot.getZ();
    	
    	if(angleX != 0) {
	    	double cos = Math.cos(angleX);
	    	double sin = Math.sin(angleX);
	    	rot = new Vector(x, y*cos + z*sin, -y*sin + z*cos);
    	}
    	
    	if(angleY != 0) {
	    	double cos = Math.cos(angleY);
	    	double sin = Math.sin(angleY);
	    	rot = new Vector(x*cos - z*sin, y, x*sin + z*cos);
    	}
    	
    	if(angleZ != 0) {
	    	double cos = Math.cos(angleZ);
	    	double sin = Math.sin(angleZ);
	    	rot = new Vector(x*cos + y * sin, -x*sin + y*cos, z);
    	}
	}
	
    public void rotateX(WorldObject o, double angle) {
    	rotate(angle, 0, 0);
    }
    
    public void rotateY(WorldObject o, double angle) {
    	rotate(0, angle, 0);
    }
    
    public void rotateZ(WorldObject o, double angle) {
    	rotate(0, 0, angle);
    }
}
