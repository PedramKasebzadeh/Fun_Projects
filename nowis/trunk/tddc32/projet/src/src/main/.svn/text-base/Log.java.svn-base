package main;
import java.util.logging.ConsoleHandler;
import java.util.logging.Level;
import java.util.logging.LogManager;



public class Log {
	private static Log instance = null;
	private java.util.logging.Logger logger;
	private ConsoleHandler handler;
	
	private Log() {
		LogManager.getLogManager().reset();
		logger = java.util.logging.Logger.getLogger(java.util.logging.Logger.GLOBAL_LOGGER_NAME);
		
		handler = new ConsoleHandler();
		handler.setFormatter(new TextFormatter());
		handler.setLevel(Level.SEVERE);
		
		logger.addHandler(handler);
		logger.setLevel(Level.FINEST);
	}
	
	public static Log getInstance() {
		if(instance == null)
			instance = new Log();
		return instance;
	}
	
	public void setVerboseDebug() {
		handler.setLevel(Level.FINEST);
	}
	
	public void setVerbose() {
		handler.setLevel(Level.INFO);
	}
	
	public void println(String msg) {
		logger.severe(msg);
	}
	
	public void verbose(String msg) {
		logger.info(msg);
	}
	
	public void debug(String msg) {
		StackTraceElement s = Thread.currentThread().getStackTrace()[2];
		logger.finest("DEBUG -- " + s.getClassName() + "." + s.getMethodName());
		logger.finest("      " + msg);
	}
}
