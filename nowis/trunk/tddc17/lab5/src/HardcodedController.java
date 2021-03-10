public class HardcodedController extends Controller {
	private static final double MAX_DELTA_HEIGHT = 200;
	private static final double MAX_DELTA_ANGLE = 0.05;
	
	private double initHeight;
	private double initAngle;
	private boolean init = true;
	
	public SpringObject object;

	ComposedSpringObject cso;
	DoubleFeature x;
	DoubleFeature y;
	DoubleFeature vx;
	DoubleFeature vy;
	DoubleFeature angle;

	RocketEngine left;
	RocketEngine middle;
	RocketEngine right;

	boolean paused = false;
	
	private enum Part {
		PART2,
		PART3,
		PART4
	};
	private static final Part PART = Part.PART3; // Select PART2, PART3 or PART4

	public void init() {
		cso = (ComposedSpringObject) object;
		x = (DoubleFeature) cso.getObjectById("x");
		y = (DoubleFeature) cso.getObjectById("y");
		vx = (DoubleFeature) cso.getObjectById("vx");
		vy = (DoubleFeature) cso.getObjectById("vy");
		angle = (DoubleFeature) cso.getObjectById("angle");

		left = (RocketEngine) cso.getObjectById("rocket_engine_left");
		right = (RocketEngine) cso.getObjectById("rocket_engine_right");
		middle = (RocketEngine) cso.getObjectById("rocket_engine_middle");

	}

	void setNoBurst() {
		left.setBursting(false);
		right.setBursting(false);
		middle.setBursting(false);
	}

	public void tick(int currentTime) {
		switch(PART) {
			case PART2 : tick_part2(currentTime); // Hardcoded
			case PART3 : tick_part3(currentTime); // State and reward
			case PART4 : tick_part4(currentTime); // Q-Learning
		}
	}
	
	public void tick_part2(int currentTime) {
		if(init){
			initHeight = y.getValue();
			initAngle = angle.getValue();
			init = false;
		}
		
		if (! paused) {
			right.setBursting(angle.getValue() > initAngle + MAX_DELTA_ANGLE);
			middle.setBursting(y.getValue() > initHeight + MAX_DELTA_HEIGHT);
			left.setBursting(angle.getValue() < initAngle - MAX_DELTA_ANGLE);
		}
	}
	
	public void tick_part3(int currentTime) {
		if(init){
			initHeight = y.getValue();
			initAngle = angle.getValue();
			init = false;
		}
		
		String simpleState = StateAndReward.getStateSimple(angle.getValue());
		String fullState = StateAndReward.getStateFull(x.getValue(), y.getValue(), 
														 vx.getValue(), vy.getValue(), 
														 angle.getValue());
		double simpleReward = StateAndReward.getRewardSimple(angle.getValue());
		double fullReward = StateAndReward.getRewardFull(vx.getValue(), vy.getValue());
		
		System.out.println("[" + simpleState + "] => " + simpleReward);
		System.out.println("[" + fullState + "] => " + fullReward);
		
		if (! paused) {
			right.setBursting(angle.getValue() > initAngle + MAX_DELTA_ANGLE);
			middle.setBursting(y.getValue() > initHeight + MAX_DELTA_HEIGHT);
			left.setBursting(angle.getValue() < initAngle - MAX_DELTA_ANGLE);
		}
	}
	
	public void tick_part4(int currentTime) {
	}
	
	public String toString() {
		return "[Hardcoded : " + "position(" + x.getValue()  + ", " + y.getValue()  + ") " + 
								 "velocity(" + vx.getValue() + ", " + vy.getValue() + ") " +
								 "angle(" + angle.getValue() + ")" + 
			   "]";
	}

	public void pause() {
		paused = true;
		setNoBurst();
	}

	public void run() {
		paused = false;
	}
}
