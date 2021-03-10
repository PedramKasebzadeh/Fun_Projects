public class TutorialController extends Controller {

    public SpringObject object;

    ComposedSpringObject cso;
    DoubleFeature x;
    DoubleFeature y;
    DoubleFeature vx;
    DoubleFeature vy;
    DoubleFeature angle;

    // Example:
    //
    // x.getValue() returns the vertical position of the rocket

    public void init() {
	cso = (ComposedSpringObject) object;
	x = (DoubleFeature) cso.getObjectById("x");
	y = (DoubleFeature) cso.getObjectById("y");
	vx = (DoubleFeature) cso.getObjectById("vx");
	vy = (DoubleFeature) cso.getObjectById("vy");
	angle = (DoubleFeature) cso.getObjectById("angle");
    }

    public void tick(int currentTime) {

	// Insert code here

    }


}
