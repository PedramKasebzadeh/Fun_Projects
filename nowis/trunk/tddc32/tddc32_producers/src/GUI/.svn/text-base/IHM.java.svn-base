package GUI;

import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JFrame;
import javax.swing.JPanel;

import workers.BoundedBuffer;
import workers.Consumer;
import workers.Producer;

public class IHM extends JFrame {
	private static final long serialVersionUID = 1L;
	
	public static final int WIDTH = 800;
	public static final int HEIGHT = 500;
	
	private JPanel pane;
	private WorkersPanel producersPanel;
	private WorkersPanel consumersPanel;

	public IHM(BoundedBuffer buffer) {
		pane = new JPanel();
		pane.setLayout(new BorderLayout());
		pane.add(new BufferPanel(buffer), BorderLayout.CENTER);
		
		producersPanel = new WorkersPanel();
		producersPanel.setPreferredSize(new Dimension(WIDTH/4, HEIGHT));
		pane.add(producersPanel, BorderLayout.WEST);

		consumersPanel = new WorkersPanel();
		consumersPanel.setPreferredSize(new Dimension(WIDTH/4, HEIGHT));
		pane.add(consumersPanel, BorderLayout.EAST);
		
	    this.setContentPane(pane);
	    this.setSize(WIDTH, HEIGHT);
	    this.setTitle("TDDC32 - Lab2 : Producers/Consumers");
	    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}
	
	public void addProducer(Producer p) {
		producersPanel.addWorker(p);
	}
	
	public void addConsumer(Consumer c) {
		consumersPanel.addWorker(c);
	}
}
