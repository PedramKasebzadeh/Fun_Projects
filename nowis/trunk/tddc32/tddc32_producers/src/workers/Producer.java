package workers;

import java.util.Random;

import GUI.WorkerPanel;

public class Producer extends Thread implements Delay, Worker {
	private long productionDelay;
	private int id;
	private BoundedBuffer buffer;
	private Random rand;

	private WorkerPanel panel = null;
	
	public Producer(BoundedBuffer buffer, int id) {
		this(0, buffer, id);
	}
	
	public Producer(long productionDelay, BoundedBuffer buffer, int id) {
		this.productionDelay = productionDelay;
		this.buffer = buffer;
		this.id = id;
		this.rand = new Random();
	}

	public void run() {
		String product;
		while(true) {
			product = String.valueOf((char) (rand.nextInt(26) + 'a') + String.valueOf(id));
			if(panel != null)
				panel.updateCharacter(product);
			
			try {
				sleep(productionDelay);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
			setStatus(Status.WAITING_ON_BUFFER_ACCESS);
			buffer.push(this, product);
			if(panel != null)
				panel.finished();
		}
	}
	
	public long getDelay() {
		return productionDelay;
	}

	public void setDelay(long delay) {
		this.productionDelay = delay;
	}

	public void setWorkerPanel(WorkerPanel panel) {
		this.panel = panel;
	}

	public void setStatus(workers.Worker.Status s) {
		if(panel != null)
			panel.updateStatus(s);
	}
}
