package parser.objectsanalysis;

import main.Log;

import org.xml.sax.Attributes;

import parser.SaxAnalysis;
import parser.SaxMarkupAnalysis;
import world.World;


public class SceneAnalysis implements SaxMarkupAnalysis {
	private SaxMarkupAnalysis markup;
	private SaxAnalysis saxAnalysis;

	public SceneAnalysis(SaxAnalysis saxAnalysis) {
		this.saxAnalysis = saxAnalysis;
		this.saxAnalysis.readParsingResult(new World());
	}

	@SuppressWarnings("unchecked")
	public void open(String qName, Attributes atts) {
		if(!qName.equals("Scene") && markup == null){
			try {
				Log.getInstance().debug("Create new instance of : " + qName);
				Class<SaxMarkupAnalysis> c = (Class<SaxMarkupAnalysis>) Class.forName("parser.objectsanalysis." + qName + "Analysis");
				markup = c.getConstructor(SaxAnalysis.class).newInstance(saxAnalysis);
				markup.open(qName, atts);
			} catch(Exception e) {
				Log.getInstance().println("Error while parsing xml file at balise " + qName);
				e.printStackTrace();
				System.exit(1);
			}
		}
	}
	
	public void close(String qName) {
		if (!qName.equals("Scene")) {
			markup.close(qName);
			markup = null;
		}
	}
}
