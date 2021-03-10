package workers;

import GUI.WorkerPanel;

public interface Worker {
	public enum Status {
		WORKING,
		WAITING_ON_BUFFER_ACCESS,
		WAITING_ON_BUFFER_STATE,
		MANIPULATING_BUFFER
	}
	
	public void setWorkerPanel(WorkerPanel panel);
	public void setStatus(Status s);
}
