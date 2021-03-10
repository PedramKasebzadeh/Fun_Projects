package parser;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.InputSource;
import org.xml.sax.XMLReader;

public class XmlParser {
	SaxAnalysis	handler;

	/**
	 * Sax configuration
	 * 
	 * @param is InputStream which have to be parsed 
	 * @param parent Callback at the end of parsing
	 */
	public XmlParser(InputSource is, Parsing parent) {
		handler = new SaxAnalysis(parent);
		try {
			SAXParserFactory factory = SAXParserFactory.newInstance();
			SAXParser saxParser = factory.newSAXParser();
			XMLReader reader = saxParser.getXMLReader();
			reader.setContentHandler(handler);
			reader.setErrorHandler(handler);
			try {
				reader.parse(is);
			} catch (Exception e) {}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
