package GUI;
import java.awt.GridLayout;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JPanel;

import workers.Worker;


public class WorkersPanel extends JPanel{
	public static final int INITIAL_NB_WORKERS = 3;
	
	private static final long serialVersionUID = 1L;
	List<WorkerPanel> workers = new ArrayList<WorkerPanel>();
	
 	public WorkersPanel() {
		this.setLayout(new GridLayout(INITIAL_NB_WORKERS, 1));
	}
	
	public void addWorker(Worker w) {
		WorkerPanel panel = new WorkerPanel(w, workers.size()+1);
		
		int nbRows = ((GridLayout) getLayout()).getRows();
		if(workers.size() == nbRows)
			((GridLayout) getLayout()).setRows(nbRows+1);
		
		workers.add(panel);
		this.add(panel);
	}
}
