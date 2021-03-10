package GUI;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.util.Iterator;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

import workers.BoundedBuffer;
import workers.Delay;


public class BufferPanel extends JPanel{
	private static final long serialVersionUID = 1L;
	
	private class SkipButton extends JButton implements ActionListener {
		private static final long serialVersionUID = 1L;

		public SkipButton() {
			super("Skip");
			this.addActionListener(this);
		}
		
		public void actionPerformed(ActionEvent e) {
			Thread t = buffer.getWorkerThread();
			if(t != null)
				t.interrupt();
		}
	}

	private BoundedBuffer buffer;
	private JLabel[] bufferLabels;
	private DelayPanel delay;
	
	public BufferPanel(BoundedBuffer buffer) {	
		this.buffer = buffer;
		this.bufferLabels = new JLabel[buffer.getSizeMax()];
		
		this.setBorder(BorderFactory.createTitledBorder("Bounded Buffer"));
		this.setLayout(new FlowLayout());
		
		for(int i=bufferLabels.length-1 ; i>=0 ; i--) {
			Font police = new Font("Default", Font.BOLD, 26);

			bufferLabels[i] = new JLabel("_");
			bufferLabels[i].setHorizontalAlignment(JLabel.CENTER);
			bufferLabels[i].setFont(police);
			bufferLabels[i].setPreferredSize(new Dimension(50, 50));
			bufferLabels[i].setBorder(BorderFactory.createMatteBorder(1, 1, 1, 5, Color.BLUE));
			bufferLabels[i].setForeground(Color.BLUE);
			this.add(bufferLabels[i]);
	
		}

		delay = new DelayPanel((Delay) buffer);
		this.add(delay);
		
		SkipButton skip = new SkipButton();
		skip.setMnemonic(KeyEvent.VK_S);
		this.add(skip);
		
		this.buffer.setBufferPanel(this);
	}
	
	public void refresh() {
		if(buffer != null) {
			int i = 0;
			Iterator<String> it = buffer.iterator();
			
			while(it.hasNext())
				bufferLabels[i++].setText(it.next().toString());
			while(i<bufferLabels.length)
				bufferLabels[i++].setText("_");
		}
	}
	
	public synchronized void changeLabelBg(int index, Color c) {
		this.refresh();
		bufferLabels[index].setOpaque(true);
		bufferLabels[index].setBackground(c);
		this.repaint();
	}
	
	public synchronized void normal(int index) {
		this.refresh();
		bufferLabels[index].setOpaque(false);
		this.repaint();		
	}
}
