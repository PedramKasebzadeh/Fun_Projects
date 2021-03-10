#!/bin/sh

ARCH="linux-i586"
case "`uname -m`" in
  "x86_64") ARCH="linux-amd64" ;;
  "sun4u") ARCH="solaris-sparc" ;;
esac

NATIVE_LIB="jogl-1.1.1-$ARCH/lib/"
CP="src/:JSAP-2.1.jar:jogl-1.1.1-$ARCH/lib/gluegen-rt.jar:jogl-1.1.1-$ARCH/lib/jogl.jar"
DEFAULT_OPT="-s 42.xml -v -t 2"

opt=$*
if [ $# -eq 0 ]; then
  opt="$DEFAULT_OPT"
fi

LD_LIBRARY_PATH="$NATIVE_LIB" java -classpath $CP main.RayTracer $opt

