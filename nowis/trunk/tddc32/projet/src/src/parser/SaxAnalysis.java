package parser;

import main.Log;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import parser.objectsanalysis.SceneAnalysis;

public class SaxAnalysis extends DefaultHandler implements Parsing {
	private Parsing parent;
	private SceneAnalysis scene = null;

	public SaxAnalysis(Parsing parent) {
		this.parent = parent;
	}

	public void startElement(final String uri, final String localName, 
			final String qName, final Attributes atts) throws SAXException {
		Log.getInstance().debug("Opening markup : " + qName);

		if (scene == null)
			scene = new SceneAnalysis(this);	
		else
			scene.open(qName, atts);
	}

	public void endElement(final String uri, final String localName, final String qName) throws SAXException {
		Log.getInstance().debug("Closing markup : " + qName);
		if(scene != null && !qName.equals("Scene")) 
			scene.close(qName);
	}

	public void endDocument() throws SAXException {
		Log.getInstance().verbose("Parsing xml file -- finished.");
	}

	public void readParsingResult(Object o) {
		parent.readParsingResult(o);
	}
}
