/*
 * smart_pointer-test-basics.cpp    Smart pointer II, Step 1.
 *
 * Testing constructors, destructor, dereferencing, indirection, assigment.
 */
#include "smart_pointer.h"
#include "Tracer.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace IDA_Smart_Pointer_II;
using namespace std;

typedef APiCPP_Tracer::Tracer<string> Trace;

int main()
{
   Trace::on();

   cout << "Default constructor inititializes to null pointer:\n";
   cout << "smart_pointer<Trace> sp0;\n\n";
   smart_pointer<Trace> sp0;

   // Small trick to check the value of the raw pointer.
   cout << "Using operator-> with ordinary member function call syntax\n";
   cout << "sp0.operator->(): " << sp0.operator->() << " (null pointer)\n\n";

   // operator* applies built-in operator* on the raw pointer ptr_, which
   // shall give an execution error for sp0, since its ptr_ is a null pointer.
   // (segmentation fault).
// cout << "*sp0: \"" << *sp0 << "\"\n\n";

   cout << "Type converting constructor inititializes with pointer to object\n";
   cout << "smart_pointer<Trace> sp1(new Trace(\"first\"));\n\n";
   smart_pointer<Trace> sp1(new Trace("first"));

   cout << "Using operator-> with ordinary member function call syntax\n";
   cout << "sp1.operator->(): " << sp1.operator->() << " (not null pointer)\n\n";

   cout << "Using operator* with ordinary member function call syntax\n";
   cout << "sp1.operator*(): \"" << sp1.operator*() << "\"\n\n";

   cout << "operator* applied the ordinary way (\"dereferencing\")\n";
   cout << "*sp1: \"" << *sp1 << "\"\n\n";

   *sp1 = Trace("assigned");
   cout << "*sp1 = \"assigned\" is performed\n*sp1: \"" << *sp1 << "\"\n\n";

   cout << "Copy constructor is used\nsmart_pointer<Trace> sp2(sp1);\n";
   smart_pointer<Trace> sp2(sp1);
   cout << "*sp2: \"" << *sp2 << "\"\n\n";

   cout << "Copy assignment operator is used:\nsp0 = sp2;\n";
   sp0 = sp2;
   cout << "*sp0: \"" << *sp0 << "\"\n\n";

   cout << "Declares and initializes raw pointer\n";
   cout << "int* px = new Trace(\"second\");\n";
   Trace* p = new Trace("second");
   cout << "\nAssignment from the raw pointer is preformed:\nsp2 = p;\n";
   sp2 = p;
   cout << "*sp2: \"" << *sp2 << "\"\n\n";

   cout << "Declares constant smart_pointer<Trace>\n";
   cout << "const smart_pointer<Trace> csp(new Trace(\"constant\"));\n";
   const smart_pointer<Trace> csp(new Trace("constant"));
   // Not possible with the current implementation, but later it will be:
// cout << "*csp: \"" << *csp << "\"\n\n";

   // Shall not be possible, ever:
// csp = sp0;
// *csp = 0;

   cout << "Copy assignment operator is used:\nsp0 = csp;\n";
   sp0 = csp;
   cout << "*sp0: \"" << *sp0 << "\"\n\n";

   return 0;
}
