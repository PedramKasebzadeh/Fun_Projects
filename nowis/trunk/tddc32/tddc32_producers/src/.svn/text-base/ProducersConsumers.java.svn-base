import workers.BoundedBuffer;
import workers.Consumer;
import workers.Producer;
import GUI.IHM;

public class ProducersConsumers {
	public static final int BUFFER_SIZE = 4;
	public static final int NB_PRODUCERS = 3;
	public static final int NB_CONSUMERS = 3;
	
	// Delay in milliseconds
	public static final int INITIAL_MANIPULATION_DELAY = 10000;
	public static final int INITIAL_PRODUCTION_DELAY = 2000;
	public static final int INITIAL_CONSUMPTION_DELAY = 3000;
	
	public static final void main(String[] args) {
		IHM ihm;
		BoundedBuffer buffer = new BoundedBuffer(BUFFER_SIZE, INITIAL_MANIPULATION_DELAY);
		Producer[] p = new Producer[NB_PRODUCERS];
		Consumer[] c = new Consumer[NB_CONSUMERS];
		
		ihm = new IHM(buffer);
		
		for(int i=0 ; i<NB_PRODUCERS ; i++) {
			p[i] = new Producer(INITIAL_PRODUCTION_DELAY, buffer, i+1);
			ihm.addProducer(p[i]);
			p[i].start();
		}
		for(int i=0 ; i<NB_CONSUMERS ; i++) {
			c[i] = new Consumer(INITIAL_CONSUMPTION_DELAY, buffer);
			ihm.addConsumer(c[i]);
			c[i].start();
		}
	
	}
}
