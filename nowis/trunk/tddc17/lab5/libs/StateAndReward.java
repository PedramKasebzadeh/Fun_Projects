public class StateAndReward {


    // The state discretization function for the angle controller
    public static String getStateSimple(double [] vals) {
	String state = "";
	// Insert your code here
	return state;
    }

    // The reward function for the angle controller
    public static double getRewardSimple(double vx, double vy) {
	double reward = 0.0;
	// Insert your code here
	return reward;
    }

    // The state discretization function for the hover controller 
    public static String getStateFull(double [] vals) {
	String state = "";
	// Insert your code here
	return state;
    }

    // The reward function for the hover controller 
    public static double getRewardFull(double vx, double vy) {
	double reward = 0.0;
	// Insert your code here
	return reward;
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
