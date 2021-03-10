package renderer;

public class NoIntersection extends Exception {
	private static final long serialVersionUID = 1L;
	
	public NoIntersection() {
		super();
	}
	
	public NoIntersection(String msg) {
		super(msg);
	}
}
