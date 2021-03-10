#!/bin/sh

ARCH="linux-i586"
case "`uname -m`" in
  "x86_64") ARCH="linux-amd64" ;;
  "sun4u") ARCH="solaris-sparc" ;;
esac

SP="src/"
CP="JSAP-2.1.jar:jogl-1.1.1-$ARCH/lib/gluegen-rt.jar:jogl-1.1.1-$ARCH/lib/jogl.jar"

echo "Compiling..."
echo "Arch : $ARCH"
echo "SP : $SP"
echo "CP : $CP\n"

javac src/main/RayTracer.java src/parser/objectsanalysis/*.java -sourcepath "$SP" -classpath "$CP" 

echo "Done."

