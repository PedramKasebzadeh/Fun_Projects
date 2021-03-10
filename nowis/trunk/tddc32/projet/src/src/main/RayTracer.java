package main;

import java.io.FileNotFoundException;
import java.io.IOException;

import parser.Controller;
import parser.InvalidSceneXMLFile;
import parser.Parser;
import renderer.Renderer;
import world.World;

import com.martiansoftware.jsap.FlaggedOption;
import com.martiansoftware.jsap.JSAP;
import com.martiansoftware.jsap.JSAPException;
import com.martiansoftware.jsap.JSAPResult;
import com.martiansoftware.jsap.Switch;

import debug.OpenGLRenderer;


public class RayTracer {
	@SuppressWarnings("unchecked")
	private static void usage(JSAP jsap, JSAPResult config) {
		// print errors (if so)
        java.util.Iterator errs = config.getErrorMessageIterator(); 
        System.err.println();
		while(errs.hasNext()) {
			System.err.println("Error: " + errs.next());
		}

		// usage
		System.err.println();
		System.err.println("Usage: java " + RayTracer.class.getName());
		System.err.println("            " + jsap.getUsage());
		System.err.println();

		// Full help
		System.err.println(jsap.getHelp());
		System.exit(1);
	}

	private static JSAPResult parseCommandLine(String[] args) {
		JSAP jsap = new JSAP();

		// Create options
		Switch help = new Switch("help")
				.setShortFlag('h') 
				.setLongFlag("help");
		help.setHelp("Show this help message.");
		
		FlaggedOption sceneFile = new FlaggedOption("sceneFile")
						.setStringParser(JSAP.STRING_PARSER)
						.setRequired(true) 
						.setShortFlag('s') 
						.setLongFlag("scene");
		sceneFile.setHelp("XML Scene file.");
		
		FlaggedOption nbThreads = new FlaggedOption("nbThreads")
						.setStringParser(JSAP.STRING_PARSER)
						.setRequired(false)
						.setDefault("1")
						.setShortFlag('t') 
						.setLongFlag("threads");
		nbThreads.setHelp("Number of threads.");

		Switch live = new Switch("live")
		.setShortFlag('l')
		.setLongFlag("live");
		live.setHelp("Live output.\nBe carefull, closing the output windows will not stop the program.");
		
		Switch verbose = new Switch("verbose")
					.setShortFlag('v')
					.setLongFlag("verbose");
		verbose.setHelp("Verbose output (enable small log details).");
		
		Switch debug = new Switch("debug")
					.setShortFlag('d')
					.setLongFlag("debug");
		debug.setHelp("Verbose debug output (extra detailed log), for debug purpose only.");
		
		Switch opengl = new Switch("opengl")
		.setShortFlag('g')
		.setLongFlag("opengl");
		opengl.setHelp("OpenGL output, for debug purpose only.");

		// Add options to JSAP Object
		try {
			jsap.registerParameter(help);
			jsap.registerParameter(sceneFile);
			jsap.registerParameter(verbose);
			jsap.registerParameter(debug);
			jsap.registerParameter(opengl);
			jsap.registerParameter(live);
			jsap.registerParameter(nbThreads);
		} catch (JSAPException e) {
			System.err.println("Error while parsing command line");
			e.printStackTrace();
		}

		// Finally parse options
		JSAPResult config = jsap.parse(args);
		if (!config.success() || config.getBoolean("help"))
			usage(jsap, config);

		return config;
	}

	public static void main(String[] args) throws FileNotFoundException, InvalidSceneXMLFile {
		World w;
		Log log = Log.getInstance();
		JSAPResult config = parseCommandLine(args);   
		String scene = config.getString("sceneFile");
		int nbThreads = Integer.valueOf(config.getString("nbThreads")); // XXX : Seems to be a problem with JSOP library (config.getInt)
		Boolean verbose = config.getBoolean("verbose");
		Boolean debug = config.getBoolean("debug");
		Boolean opengl = config.getBoolean("opengl");
		Boolean live = config.getBoolean("live");
		
		if(nbThreads < 0) {
			log.println("Nb threads must be greater or equal than 1. Value default setted to 1.");
			nbThreads = 1;
		}
		
		if(verbose)
			log.setVerbose();
		if(debug)
			log.setVerboseDebug();
		
		log.verbose("File : " + scene);
		log.verbose("Threads : " + nbThreads);
		log.verbose("Live : " + live);
		log.verbose("Verbose : " + verbose);
		log.verbose("debug : " + debug);
		log.verbose("opengl : " + opengl);

		// Parse scene file
		log.verbose("Parsing Scene file... ");
		new Parser(scene);
		log.verbose("... Done.");
		
		// Control world objects
		w = Controller.getInstance().getWorld();
		log.verbose(w.toString());
		if(!w.valid()) {
			log.println("Scene file need one light, one camera and at least one object.\nExiting.");
			System.exit(1);
		}

		// Output image with opengl (XXX : Doesn't print all objects !)
		if(opengl)
			OpenGLRenderer.render(w);
		
		// Output live constructing image
		if(live)
			w.getCamera().getViewPort().initFrame();
		
		// Render scene
		try {
			long start = System.currentTimeMillis(); 
			Renderer.Render(scene.substring(0,scene.lastIndexOf('.')), "png", w, nbThreads);
			log.verbose("Exec time : " + (System.currentTimeMillis() - start) + "ms");
		} catch (IOException e) {
			log.println("Problem while writing file");
			e.printStackTrace();
		}
		
		log.println("Scene rendered.");
	}
}
