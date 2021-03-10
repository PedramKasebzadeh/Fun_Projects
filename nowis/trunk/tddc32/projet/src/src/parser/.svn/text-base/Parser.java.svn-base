package parser;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;

import main.Log;

import org.xml.sax.InputSource;

public class Parser implements Parsing {
	public Parser(String filename) throws FileNotFoundException {
		try {
			InputStreamReader is = new InputStreamReader(new FileInputStream(filename), "UTF-8");
			new XmlParser(new InputSource(is), this);
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		}
	}
	
	public void readParsingResult(Object o) {
		try {
			Controller.getInstance().handleObject(o);
		} catch (InvalidSceneXMLFile e) {
			Log.getInstance().println("Error while parsing Scene XML File.");
			e.printStackTrace();
			System.exit(1);
		}	
	}
}
