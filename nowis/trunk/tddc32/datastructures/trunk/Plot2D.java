import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.HeadlessException;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JFrame;

public class Plot2D extends JFrame {
	private static final long serialVersionUID = 1L;
	
	protected int width;
	protected int height;
	protected BufferedImage img;
	protected ImagePanel panel;
	protected Graphics2D gr;
	
	protected List<List<Integer>> curvesX;
	protected List<List<Integer>> curvesY;
	protected List<Color> curvesColor;
	
	protected int maxX = 0;
	protected int maxY = 0;
	
	public Plot2D(String title, int width, int height) throws HeadlessException {
		super(title);
		this.width = width;
		this.height = height;
		
		this.curvesX = new ArrayList<List<Integer>>();
		this.curvesY = new ArrayList<List<Integer>>();
		this.curvesColor = new ArrayList<Color>();
		
		this.img = new BufferedImage(this.width, this.height, BufferedImage.TYPE_3BYTE_BGR);
		this.gr = this.img.createGraphics();
		this.panel = new ImagePanel(this.img);

		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(this.width+50, this.height+50);

		redraw();
		
		this.setContentPane(this.panel);  
		this.setVisible(true);
	}

	public void repaint() {
		panel.repaint() ;
	}
	
	public void addCurve(int[] X, int[] Y, Color c) {
		if(X.length != Y.length)
			throw new IllegalArgumentException("Size of arrays X and Y must be the same !");
		
		ArrayList<Integer> newCurve = new ArrayList<Integer>();
		for(int i : X) {
			if(i >= maxX)
				maxX = i;
			newCurve.add(i);
		}
		curvesX.add(newCurve);
		
		newCurve = new ArrayList<Integer>();
		for(int i : Y) {
			if(i >= maxY)
				maxY = i;
			newCurve.add(i);
		}
		curvesY.add(newCurve);	
		
		curvesColor.add(c);
		
		redraw();
	}
	
	private void redraw() {
		// Clean blackboard
		this.gr.setColor(Color.white);
		this.gr.fillRect(0, 0, this.width, this.height);
		
		if(!curvesX.isEmpty())
			drawAxis();
		
		for(int i=0 ; i<curvesX.size() ; i++) {
			this.gr.setColor(curvesColor.get(i));
			drawCurve(curvesX.get(i), curvesY.get(i));
		}
		
		this.repaint();
	}

	private void drawAxis() {
		int stepX = maxX / 20;
		int stepY = maxY / 20;
		
		this.gr.setColor(Color.black);
		this.gr.setStroke(new BasicStroke(2));
		this.gr.drawLine(40, height-20, 40, 20);
		this.gr.drawLine(40, height-20, width, height-20);
	
		for(int i=0 ; i<=maxX ; i+=stepX) {
			int x = projx(i);
			
			this.gr.drawLine(x, height-20, x, height-15);
			this.gr.drawString(Integer.toString(i), x, height);
		}
		
		for(int i=0 ; i<=maxY ; i+=stepY) {
			int y = projy(i);
			
			this.gr.drawLine(40, y, 35, y);
			this.gr.drawString(Integer.toString(i), 0, y);
		}
	}
	
	private void drawCurve(List<Integer> curveX, List<Integer> curveY) {
		for(int i=0 ; i<curveX.size()-1 ; i++) {
			int x1 = projx(curveX.get(i));
			int y1 = projy(curveY.get(i));
			int x2 = projx(curveX.get(i+1));
			int y2 = projy(curveY.get(i+1));
			
			this.gr.drawLine(x1, y1, x2, y2);
		}
	}
	
	private int projx(int i) {
		return 40 + (int) (((float) i/ maxX)*(float) (width-40));
	}
	
	private int projy(int i) {
		return (height-20) - (int) (((float) i/ maxY)*(float) (height-40));
	}
}
