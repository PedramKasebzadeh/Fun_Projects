package world;

public class Vector {
	private double x;
	private double y;
	private double z;

	public Vector(double x, double y, double z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}

	public double getX() {
		return x;
	}

	public void setX(double x) {
		this.x = x;
	}

	public double getY() {
		return y;
	}

	public void setY(double y) {
		this.y = y;
	}

	public double getZ() {
		return z;
	}

	public void setZ(double z) {
		this.z = z;
	}
	
	public void set(double x, double y, double z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}
	
	public void translate(Vector vect) {
		this.x += vect.x;
		this.y += vect.y;
		this.z += vect.z;
	}

	public double getNorm() {
		return Math.sqrt(this.scalarProduct(this));
	}
	
	/**
	 * Return the scalar product of the current Vector and the vector vect
	 * @param vect
	 * @return double
	 */
	public double scalarProduct(Vector vect) {
		return this.x*vect.x + this.y*vect.y + this.z*vect.z;
	}


	/**
	 * Return the difference of the current Vector and the vector vect
	 * @param vect
	 * @return Vector
	 */
	public Vector minus(Vector vect) {
		return new Vector(this.x-vect.x, this.y-vect.y, this.z-vect.z);
	}

	/**
	 * Return the addition of the current Vector and the vector vect
	 * @param vect
	 * @return Vector
	 */
	public Vector add(Vector vect) {
		return new Vector(this.x+vect.x, this.y+vect.y, this.z+vect.z);
	}

	/**
	 * Make this vector a unit vector
	 */
	public void unitize() {
		double norm = this.getNorm();
		this.x /= norm;
		this.y /= norm;
		this.z /= norm;
	}
	
	/**
	 * Return dist*thisVector;
	 * @param dist
	 * @return Vector
	 */
	public Vector multiply(double dist) {
		return new Vector(dist*x, dist*y, dist*z);
	}
	
	/**
	 * Return a text represention of the vector (x;y;z)
	 * @return String
	 */
	public String toString() {
		return "(" + x + ";" + y + ";" + z + ")";
	}
}
