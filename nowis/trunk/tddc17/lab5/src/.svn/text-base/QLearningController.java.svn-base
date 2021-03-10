import java.io.*;
import java.lang.reflect.Method;
import java.util.HashMap;

public class QLearningController extends Controller {
	public static final boolean SIMPLE_REWARD = true; // Simple reward or full reward
	public static final double EPSILON = 0.05;
	
	enum Action {
		LEFT,
		MIDDLE,
		RIGHT,
		BURSTINGOFF
	};
	
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

	HashMap<String, Double> qfunc;
	
	TestPairs pairs = new TestPairs();
	double sumReward = 0.0;
	int nrTicks = 0;
	int nrWrites = 0;
	
	double QInitial = 20;
	
	@SuppressWarnings("unused")
	private void actions_LEFT() {
		left.setBursting(true);
	}
	
	@SuppressWarnings("unused")
	private void actions_RIGHT() {
		right.setBursting(true);
	}
	
	@SuppressWarnings("unused")
	private void actions_MIDDLE() {
		middle.setBursting(true);
	}
	
	@SuppressWarnings("unused")
	private void actions_BURSTINGOFF() {
		left.setBursting(false);
		right.setBursting(false);
		middle.setBursting(false);
	}
	
	public void executeAction(Action ac) {
		try {
			this.getClass().getMethod("actions_" + ac).invoke(this);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
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

		qfunc = new HashMap<String, Double>();
		
		for(int i=0 ; i<StateAndReward.VELOCITY_DISCRETIZATION ; i++) {
			for(int j=0 ; j<StateAndReward.VELOCITY_DISCRETIZATION ; j++) {	
				for(int k=0 ; k<StateAndReward.ANGLE_DISCRETIZATION ; k++) {
					for(Action ac : Action.values()) {
						qfunc.put(String.valueOf(i) + String.valueOf(j) + String.valueOf(k) + "_" + ac,
								  QInitial);
					}
				}
			}
		}
	}

	void setNoBurst() {
		left.setBursting(false);
		right.setBursting(false);
		middle.setBursting(false);
	}

	public void tick(int currentTime) {
		if (! paused) {
			double reward;
			String state;
			Action action = Action.BURSTINGOFF;
			if(SIMPLE_REWARD) {
				state = StateAndReward.getStateSimple(angle.getValue());
				reward = StateAndReward.getRewardSimple(angle.getValue());
			} else {
				state = StateAndReward.getStateFull(x.getValue(), y.getValue(), 
													vx.getValue(), vy.getValue(), 
													angle.getValue());
				reward = StateAndReward.getRewardFull(vx.getValue(), vy.getValue());
			}
			
			// Q-Leaning
			for(Action ac : Action.values()) {
				double new_value = qfunc.remove(state + "_" + ac) + EPSILON*(reward);
				qfunc.put(state + "_" + ac, new_value);
				updateStats(reward);
			}

		}
	}


	public void pause() {
		paused = true;
		setNoBurst();
	}


	public void run() {
		paused = false;
	}


	public void performCommand(String command) {
		super.performCommand(command);
	}

	public void updateStats(double currentReward) {
		int nrTicksBeforeStat = 10000; // An example
		if (nrTicks >= nrTicksBeforeStat) {
			TestPair p = new TestPair(nrTicksBeforeStat * nrWrites, (sumReward / nrTicksBeforeStat));
			pairs.addPair(p);
			try {
				writeToFile("output.m", pairs.getMatlabString("steps", "result"));
			} catch (Exception e) {
				e.printStackTrace();
			}
			sumReward = currentReward;
			nrTicks = 0;
			nrWrites++;
		} else {
			nrTicks++;
			sumReward += currentReward;
		}
	}

	public void writeToFile(String filename, String content) {
		try {
			FileOutputStream fos = new FileOutputStream(filename);
			fos.write(content.getBytes());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
