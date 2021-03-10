package world.unittests;

import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

@RunWith(value=Suite.class)
@SuiteClasses(value={TestVector.class, TestCube.class, TestCylinder.class, TestSphere.class})
public class TestSuite {
}
