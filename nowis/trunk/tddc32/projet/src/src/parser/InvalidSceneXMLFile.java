package parser;

public class InvalidSceneXMLFile extends Exception {
	private static final long serialVersionUID = 1L;

	public InvalidSceneXMLFile() {
		super();
	}
	
	public InvalidSceneXMLFile(String msg) {
		super(msg);
	}
}
