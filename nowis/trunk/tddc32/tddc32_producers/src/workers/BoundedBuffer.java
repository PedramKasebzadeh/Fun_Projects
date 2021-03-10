package workers;

import java.awt.Color;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

import workers.Worker.Status;

import GUI.BufferPanel;

public class BoundedBuffer implements Delay {
	private Queue<String> buffer;
	private int sizeMax;
	private long manipulationDelay;
	private BufferPanel bufferPanel = null;
	private Thread workerThread = null;
	
	public BoundedBuffer() {
		this(4, 0);
	}
	
	public BoundedBuffer(int sizeMax, long manipulationDelay) {
		this.buffer = new LinkedList<String>();
		this.sizeMax = sizeMax;
		this.manipulationDelay = manipulationDelay;
	}
	
	public synchronized void push(Worker w, String s) {
		while(buffer.size() == sizeMax) {
			w.setStatus(Status.WAITING_ON_BUFFER_STATE);
			try {
				wait();
			}catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
		buffer.add(s);

		if(bufferPanel != null)
			bufferPanel.changeLabelBg(buffer.size()-1, Color.green);

		manipulate(w);
		
		if(bufferPanel != null)
			bufferPanel.normal(buffer.size()-1);
		
		notify();
	}
	
	public synchronized String pop(Worker w) {
		String result;
		
		while(buffer.isEmpty()) {
			w.setStatus(Status.WAITING_ON_BUFFER_STATE);
			try {
				wait();
			}catch(InterruptedException e) {
				e.printStackTrace();
			}
		}

		if(bufferPanel != null)
			bufferPanel.changeLabelBg(0, Color.red);
		
		manipulate(w);
		
		result = buffer.poll();
		if(bufferPanel != null)
			bufferPanel.normal(0);
		
		notify();
		return result;
	}

	private void manipulate(Worker w) {
		w.setStatus(Status.MANIPULATING_BUFFER);
		try {
			workerThread = Thread.currentThread();
			Thread.sleep(manipulationDelay);
		} catch (InterruptedException e) {
			System.out.println("skipped");
		} finally {
			workerThread = null;
		}
	}
	
	public Iterator<String> iterator() {
		return buffer.iterator();
	}

	public int getSizeMax() {
		return sizeMax;
	}
	
	public void setBufferPanel(BufferPanel bufferPanel) {
		this.bufferPanel = bufferPanel;
	}

	public long getDelay() {
		return manipulationDelay;
	}

	public void setDelay(long delay) {
		this.manipulationDelay = delay;
	}
	
	public Thread getWorkerThread() {
		return workerThread;
	}
}
