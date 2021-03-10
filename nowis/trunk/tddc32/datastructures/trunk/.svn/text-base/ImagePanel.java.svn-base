import javax.swing.* ;
import java.awt.* ;

public class ImagePanel extends JPanel {
	private static final long serialVersionUID = 1L;
	private Image image;

	public ImagePanel(Image image) {
		this.image = image;
	}

	public void setImage(Image image) {
		this.image = image;
	}

	public void paintComponent(Graphics g) {
		g.drawImage(image, 0, 0, this);
	}

	public Dimension getPreferredSize() {
		return new Dimension(0, 0);
	}
}
