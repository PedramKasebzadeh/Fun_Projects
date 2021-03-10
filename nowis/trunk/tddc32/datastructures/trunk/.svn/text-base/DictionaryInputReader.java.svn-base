import java.io.EOFException;
import java.io.FileInputStream;
import java.io.IOException;

public class DictionaryInputReader extends FileInputStream {
	
	public DictionaryInputReader(String name) throws IOException {
		super(name);
		
		skipHeader();
	}

	private void skipHeader() throws IOException {
		for(int i=0 ; i<7 ; i++) {
			while((char) this.read() != '\n') {
			}
		}
	}

	public String nextWord() throws IOException {
		char current = (char) this.read();
		String result = "";
		
		while(current != '\n' && current != '\r' && current != '\t' && current != ' ') {
			//System.out.println("Nyu" + current);
			if(current == -1)
				throw new EOFException();
			result += String.valueOf(current);
			current = (char) this.read();
		}
		
		return result;
	}
}
