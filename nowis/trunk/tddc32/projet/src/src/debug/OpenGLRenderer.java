package debug;

import java.awt.Color;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLCanvas;
import javax.media.opengl.GLEventListener;
import javax.media.opengl.glu.GLU;
import javax.media.opengl.glu.GLUquadric;
import javax.swing.JFrame;

import renderer.Viewport;

import world.Camera;
import world.Sphere;
import world.Vector;
import world.World;
import world.WorldObject;

import com.sun.opengl.util.Animator;

public class OpenGLRenderer implements GLEventListener {
	private GLU glu;
	private static World w;

	public static void render(World w) {
		OpenGLRenderer.w = w;
		JFrame frame = new JFrame("OpenGL Debug");
		frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		GLCanvas canvas = new GLCanvas();

		canvas.addGLEventListener(new OpenGLRenderer());
		frame.add(canvas);
		final Animator animator = new Animator(canvas);

		frame.setSize(640, 480);
		frame.setVisible(true);

		animator.start();
	}

	private void setCamera(GL gl, float distance, Camera c) {
		Vector pos = c.getPos();
		Vector dir = c.getDirection();

		// Change to projection matrix.
		gl.glMatrixMode(GL.GL_PROJECTION);
		gl.glLoadIdentity();

		// Perspective.
		float widthHeightRatio = (float) 640 / (float) 480;
		glu.gluPerspective(45, widthHeightRatio, 1, 1000);
		glu.gluLookAt(pos.getX(), pos.getY(), pos.getZ(),
				dir.getX(), dir.getY(), dir.getZ(),
				0, 0, 1);

		// Change back to model view matrix.
		gl.glMatrixMode(GL.GL_MODELVIEW);
		gl.glLoadIdentity();
	}

	public void setLight(GL gl) {/*
    	// Prepare light parameters.
        float SHINE_ALL_DIRECTIONS = 1;
        float[] lightPos = {0, 0, 0, SHINE_ALL_DIRECTIONS};
        float[] lightColorAmbient = {0.3f, 0.3f, 0.3f, 1f};
        float[] lightColorSpecular = {0.8f, 0.8f, 0.8f, 1f};

        // Set light parameters.
        gl.glLightfv(GL.GL_LIGHT1, GL.GL_POSITION, lightPos, 0);
        gl.glLightfv(GL.GL_LIGHT1, GL.GL_AMBIENT, lightColorAmbient, 0);
        gl.glLightfv(GL.GL_LIGHT1, GL.GL_SPECULAR, lightColorSpecular, 0);

        // Enable lighting in GL.
        gl.glEnable(GL.GL_LIGHT1);
        gl.glEnable(GL.GL_LIGHTING);

        // Set material properties.
        float[] rgba = {0.3f, 0.5f, 1f};
        gl.glMaterialfv(GL.GL_FRONT, GL.GL_AMBIENT, rgba, 0);
        gl.glMaterialfv(GL.GL_FRONT, GL.GL_SPECULAR, rgba, 0);
        gl.glMaterialf(GL.GL_FRONT, GL.GL_SHININESS, 0.5f);*/
	}

	public void setViewport(GL gl, Viewport vp) {
		Vector v = vp.getOrigin();
		float y1 = (float) v.getY();
		float z1 = (float) v.getZ();
		float y2 = y1 + (float) vp.getRealWidth();
		float z2 = z1 - (float) vp.getRealHeight();
		
		gl.glLoadIdentity();

		gl.glEnable(GL.GL_BLEND);
		gl.glBlendFunc(GL.GL_SRC_ALPHA, GL.GL_ONE_MINUS_SRC_ALPHA) ;
		gl.glEnable(GL.GL_CULL_FACE);
		
		gl.glBegin(GL.GL_QUADS); {
			gl.glColor4f(1.0f, 1.0f, 1.0f, 0.25f);
			gl.glVertex3f((float) v.getX(), y1, z1);
			gl.glVertex3f((float) v.getX(), y2, z1);
			gl.glVertex3f((float) v.getX(), y2, z2);
			gl.glVertex3f((float) v.getX(), y1, z2);
		} gl.glEnd();
		
		gl.glFlush();

		gl.glLoadIdentity();
	}

	public void display(GLAutoDrawable drawable) {
		GL gl = drawable.getGL();
		gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);

		setCamera(gl, 100, w.getCamera());
		setLight(gl);

		for(WorldObject o : w.getObjects()) {
			gl.glLoadIdentity();
			Color c = o.getColor();
			Vector v = o.getPosition();

			if(o instanceof Sphere) {
				
				gl.glColor3f(c.getRed(), c.getGreen(), c.getBlue());
				gl.glTranslatef((float)v.getX(), (float)v.getY(), (float)v.getZ());
				GLUquadric sphere = glu.gluNewQuadric();
				glu.gluQuadricDrawStyle(sphere, GLU.GLU_FILL);
				glu.gluQuadricNormals(sphere, GLU.GLU_FLAT);
				glu.gluQuadricOrientation(sphere, GLU.GLU_OUTSIDE);
				double radius = ((Sphere) o).getRadius();
				int slices = 16;
				int stacks = 16;
				glu.gluSphere(sphere, radius, slices, stacks);
				glu.gluDeleteQuadric(sphere);
			}
		}
		
		setViewport(gl, w.getCamera().getViewPort());
	}

	public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged) {}

	public void init(GLAutoDrawable drawable) {
		glu = new GLU();
		GL gl = drawable.getGL();
		gl.setSwapInterval(1);
	}

	public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
		GL gl = drawable.getGL();
		gl.glViewport(0, 0, width, height);
	}
}
