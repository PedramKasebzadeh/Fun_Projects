package main;
import java.util.logging.Handler;
import java.util.logging.LogRecord;
import java.util.logging.SimpleFormatter;


public class TextFormatter extends SimpleFormatter {
	 public String format(LogRecord record) {
		 return formatMessage(record) + "\n";
	 }
	 
	 public String getHead(Handler h) {
		 return "-- Beginning logging --\n";
	 }
	 
	 public String getTail(Handler h) {
		 return "-- End logging --\n";
	 }
}
