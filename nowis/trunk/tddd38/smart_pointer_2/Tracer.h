/*
 * Tracer.h
 *
 * Helper class for producing output showing how objects are created, 
 * copied and destroyed.
 */
#ifndef TRACER_H
#define TRACER_H
#include <iostream>

namespace APiCPP_Tracer
{
   template<typename T>
   struct Tracer
   {
      public:
	 Tracer() : value() {
	    if (trace) std::cout << "TRACE: default ctor for new Tracer[" << this << "]\n";
	 }

	 Tracer(const T& init) : value(init) {
	    if (trace) std::cout << "TRACE: ctor for new Tracer[" << this << "](" << value << ")\n";
	 }

	 Tracer(const Tracer& t) : value(t.value) {
	    if (trace) std::cout << "TRACE: copy ctor for new Tracer[" << this << "](" << &t << ")\n";
	 }

	 Tracer& operator=(const Tracer& t) {
	    value = t.value;
	    if (trace) std::cout << "TRACE: copy assignment for Tracer[" << this << "] = " << &t << "\n";
	    return *this;
	 }

	 ~Tracer() {
	    if (trace) std::cout << "TRACE: destructor for disappearing Tracer[" << this << "]\n";
	 }

	 static void on()  { trace = true; }
	 static void off() { trace = false; }
	 static bool trace;      

	 T value;

      private:
	 // Declare special member functions not needed here.
	 // Tracer(const Tracer& t);
	 // Tracer& operator=(const Tracer& t);
   };

   template<typename T>
   std::ostream& operator<<( std::ostream& os, const Tracer<T>& t) {
      return os << t.value;
   }

   template<typename T>
   bool Tracer<T>::trace(true);

} // namespace APiCPP_Tracer

#endif
