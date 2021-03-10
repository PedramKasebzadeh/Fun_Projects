public class QLearningController extends Controller {

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

	if (! paused) {
	    // Insert code here for the Q-learning controller
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

}

