import java.io.PipedOutputStream;

public class StateAndReward {
	public static int POSITION_DISCRETIZATION = 20;
	public static int VELOCITY_DISCRETIZATION = 5;
	public static int ANGLE_DISCRETIZATION = 5;
	
	public static int MIN_X = 200;
	public static int MAX_X = 3200;
	public static int MIN_Y = -800;
	public static int MAX_Y = 1200;
	public static int MIN_VX = -5;
	public static int MAX_VX = 5;
	public static int MIN_VY = -5;
	public static int MAX_VY = 5;
	public static int MIN_ANGLE = -1;
	public static int MAX_ANGLE = 1;
	
	public static int MAX_REWARD = 2;
	

	// The state discretization function for the angle controller
	// size of the Q-function : ANGLE_DISCRETIZATION*4 = 20;
	public static String getStateSimple(double angle) {
		return String.valueOf(discretize(angle, ANGLE_DISCRETIZATION, MIN_ANGLE, MAX_ANGLE));
	}

	// The reward function for the angle controller
	public static double getRewardSimple(double angle) {
		return -Math.abs(angle);
	}

	// The state discretization function for the hover controller 
	// size of the Q-function : POSITION_DISCRETIZATION*VELOCITY_DISCRETIZATION*ANGLE_DISCRETIZATION*6 = 500;
	public static String getStateFull(double x, double y, double vx, double vy, double angle) {
		String state = "";
		//state += String.valueOf(discretize(x, POSITION_DISCRETIZATION, MIN_X, MAX_X));
		//state += String.valueOf(discretize(y, POSITION_DISCRETIZATION, MIN_Y, MAX_Y));
		state += String.valueOf(discretize(vx, VELOCITY_DISCRETIZATION, MIN_VX, MAX_VX));
		state += String.valueOf(discretize(vy, VELOCITY_DISCRETIZATION, MIN_VY, MAX_VY));
		state += String.valueOf(discretize(angle, ANGLE_DISCRETIZATION, MIN_ANGLE, MAX_ANGLE));
		return state;
	}

	// The reward function for the hover controller 
	public static double getRewardFull(double vx, double vy) {
		return MAX_REWARD - Math.abs(vx) - Math.abs(vy);
	}

	/////////////////////////////////////////////////////////////
	// discretize() performs a uniform discretization of the 
	// value parameter.
	// It returns an integer between 0 and nrValues-1.
	// The min and max parameters are used to specify the interval
	// for the discretization.
	// If the value is lower than min, 0 is returned
	// If the value is higher than min, nrValues-1 is returned
	// otherwise a value between 1 and nrValues-2 is returned.
	//
	// Use discretize2() if you want a discretization method that does 
	// not handle values lower than min and higher than max.
	/////////////////////////////////////////////////////////////
	public static int discretize(double value, int nrValues,
			double min, double max) {
		if (nrValues < 2) {
			return 0;
		}

		double diff = max - min;

		if (value < min) {
			return 0;
		}
		if (value > max) {
			return nrValues - 1;
		}

		double tempValue = value - min;
		double ratio = tempValue / diff;

		return (int) (ratio * (nrValues - 2)) + 1;
	}




	/////////////////////////////////////////////////////////////
	// discretize2() performs a uniform discretization of the 
	// value parameter.
	// It returns an integer between 0 and nrValues-1.
	// The min and max parameters are used to specify the interval
	// for the discretization.
	// If the value is lower than min, 0 is returned
	// If the value is higher than min, nrValues-1 is returned
	// otherwise a value between 0 and nrValues-1 is returned.
	/////////////////////////////////////////////////////////////
	public static int discretize2(double value, int nrValues,
			double min, double max) {
		double diff = max - min;

		if (value < min) {
			return 0;
		}
		if (value > max) {
			return nrValues - 1;
		}

		double tempValue = value - min;
		double ratio = tempValue / diff;

		return (int) (ratio * nrValues);
	}

}
