package tddc17;

public class Cell {
	public enum Status {
		UNKNOWN,
		HOME,
		WALL,
		EMPTY,
		DIRT
	}
	
	private int x;
	private int y;
	private Status status;
	private boolean marked = false;
	private int distanceFromHome = 0;

	public Cell(int x, int y) {
		this(x, y, Status.UNKNOWN);
	}
	
	public Cell(int x, int y, Status status) {
		this.x = x;
		this.y = y;
		this.status = status;
	}

	public void setStatus(Status status) {
		this.status = status;
	}
	
	public Status getStatus() {
		return status;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}
	
	public boolean isMarked() {
		return marked;
	}

	public void setMarked(boolean mark) {
		this.marked = mark;
	}
	
	public boolean isWall() {
		return status == Status.WALL;
	}

	public boolean isHome() {
		return status == Status.HOME;
	}
	
	public boolean isDirty() {
		return status == Status.DIRT;
	}
	
	public boolean isUnknown() {
		return status == Status.UNKNOWN;
	}
	
	public boolean isEmtpy() {
		return status == Status.EMPTY;
	}
	
	public int getDistanceFromHome() {
		return distanceFromHome;
	}

	public void setDistanceFromHome(int distanceFromHome) {
		this.distanceFromHome = distanceFromHome;
	}
	
	public boolean equals(Cell c) {
		return this.x ==c.x && this.y == c.y;
	}
	
	public String toString() {
		return (status == Status.WALL ? "X" : "  ");
	}
}
