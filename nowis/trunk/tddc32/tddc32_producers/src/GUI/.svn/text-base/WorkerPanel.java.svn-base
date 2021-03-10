package GUI;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;

import javax.swing.BorderFactory;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

import workers.Delay;
import workers.Worker;
import workers.Worker.Status;

public class WorkerPanel extends JPanel {
	private static final long serialVersionUID = 1L;
	
	private JTextArea workerLabel;
	private DelayPanel delay;
	private int nbProducts = 0;
	private Status status = Status.WORKING;
	private JTextArea statusLabel;
	
	public WorkerPanel(Worker w, int number) {
		this.setLayout(new BorderLayout());
		this.setBorder(BorderFactory.createTitledBorder("Worker"));
	
		workerLabel = new JTextArea("");
		workerLabel.setOpaque(false);
		workerLabel.setFont(new Font("Default", Font.BOLD, 14));
		workerLabel.setPreferredSize(new Dimension(50, 50));
		workerLabel.setBorder(BorderFactory.createMatteBorder(1, 1, 1, 1, Color.BLUE));
		workerLabel.setForeground(Color.BLUE);
		workerLabel.setLineWrap(true);
		workerLabel.setWrapStyleWord(true); 
		this.add(workerLabel, BorderLayout.CENTER);

		statusLabel = new JTextArea();
		statusLabel.setOpaque(false);
		updateStatus(status);
		this.add(statusLabel, BorderLayout.NORTH);

		delay = new DelayPanel((Delay) w);
		this.add(delay, BorderLayout.SOUTH);
	
		w.setWorkerPanel(this);
	}
	
	public void updateCharacter(String prod) {
		workerLabel.setText(workerLabel.getText() + " " + prod);
		updateStatus(Status.WORKING);
		nbProducts++;
		updateStatus(status);
	}
	
	public void finished() {
		//workerLabel.setText("_");
	}
	
	public void updateStatus(Status s) {
		status = s;
		statusLabel.setText("#" + nbProducts + "\n" + status.toString());
	}
}
