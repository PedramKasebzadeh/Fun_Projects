package workers;

import GUI.WorkerPanel;

public class Consumer extends Thread implements Delay, Worker {
	private long consumptionDelay;
	private BoundedBuffer buffer;

	private WorkerPanel panel = null;
	
	public Consumer(BoundedBuffer buffer) {
		this(0, buffer);
	}
	
	public Consumer(long consumptionDelay, BoundedBuffer buffer) {
		this.consumptionDelay = consumptionDelay;
		this.buffer = buffer;
	}

	public void run() {
		while(true) {
			setStatus(Status.WAITING_ON_BUFFER_ACCESS);
			String product = buffer.pop(this);
			if(panel != null)
				panel.updateCharacter(product);
			
			try {
				sleep(consumptionDelay);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
			if(panel != null)
				panel.finished();
		}
	}

	public long getDelay() {
		return consumptionDelay;
	}

	public void setDelay(long delay) {
		this.consumptionDelay = delay;
	}

	public void setWorkerPanel(WorkerPanel panel) {
		this.panel = panel;
	}

	public void setStatus(Status s) {
		if(panel != null)
			panel.updateStatus(s);
	}
}
