package GUI;

import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import workers.Delay;

public class DelayPanel extends JPanel {
	private static final long serialVersionUID = 1L;
	
	private class DelayTextField extends JTextField implements KeyListener  {
		private static final long serialVersionUID = 1L;

		public DelayTextField(String s) {
			super(s);
			this.addKeyListener(this);
		}
		
		public void keyPressed(KeyEvent e) {}
		public void keyReleased(KeyEvent e) {}

		public void keyTyped(KeyEvent e) {
			if(e.getKeyChar() == KeyEvent.VK_ENTER) {
				try {
					delayUser.setDelay(Long.parseLong(getText()));
					System.out.println("[" + delayUser + "] New delay value : " + getText());
				} catch(NumberFormatException exception) {
					System.out.println("Valeur " + getText() + " incorrecte");;
					setText(Long.toString(delayUser.getDelay()));
				}
			}
		}
	}
	
	private Delay delayUser;
	private DelayTextField text;
	
	public DelayPanel(Delay delay) {
		super();
		
		this.delayUser = delay;
		
		this.setLayout(new FlowLayout());
		text = new DelayTextField(Long.toString(this.delayUser.getDelay()));
		text.setPreferredSize(new Dimension(70, 20));
		this.add(new JLabel("Delay :"));
		this.add(text);
		this.add(new JLabel("ms"));
	}
}
