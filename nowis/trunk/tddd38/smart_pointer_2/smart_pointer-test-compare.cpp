/*
 * smart_pointer-test-compare.cpp    Smart pointer II, Step 2.
 *
 * Testing basic versions of operator== and operator!= 
 */
#include "smart_pointer.h"
#include "Tracer.h"
#include <iostream>
#include <iomanip>
using namespace IDA_Smart_Pointer_II;
using namespace std;

typedef APiCPP_Tracer::Tracer<string> Trace;

int main()
{
   Trace::on();

   cout << "Declaring two smart pointers, sp1 and sp2\n";
   cout << "smart_pointer<Trace> sp1(new Trace(\"first\"));\n";
   cout << "smart_pointer<Trace> sp2(new Trace(\"second\"));\n";
   smart_pointer<Trace> sp1(new Trace("first"));
   smart_pointer<Trace> sp2(new Trace("second"));

   cout << "\nComparing two smart pointers using == and !=\n";
   if (sp1 == sp1) cout << "sp1 == sp1: true\n"; else cout << "sp1 == sp1: false\n";
   if (sp1 == sp2) cout << "sp1 == sp2: true\n"; else cout << "sp1 == sp2: false\n";
   if (sp1 != sp1) cout << "sp1 != sp1: true\n"; else cout << "sp1 != sp1: false\n";
   if (sp1 != sp2) cout << "sp1 != sp2: true\n"; else cout << "sp1 != sp2: false\n";

   cout << "\nDeclaring a raw pointer, p\n";
   cout << "int* p = new Trace(\"tredje\");\n";
   Trace* p = new Trace("tredje");

   cout << "\nnComparing smart pointer and raw pointer using == and !=\n";
   if (sp1 == p) cout << "sp1 == p: true\n";   else cout << "sp1 == p: false\n";
   if (p == sp1) cout << "p == sp1: true\n"; else cout << "p == sp1: false\n";
   if (sp1 != p) cout << "sp1 != p: true\n";   else cout << "sp1 != p: false\n";
   if (p != sp1) cout << "p != sp1: true\n"; else cout << "p != sp1: false\n";

   cout << "\nnDeclaring a null smart pointer, sp0\n";
   cout << "smart_pointer<Trace> sp0;\n";
   smart_pointer<Trace> sp0;

   // Direct null pointer test is not possible, there is no type conversion to bool
// if (sp0) cout << "sp0    : true\n"; else cout << "sp0    : false\n";
// if (sp1) cout << "sp1    : true\n"; else cout << "sp1    : false\n";

   cout << "\nNegated direct null pointer test (sp0 is a null pointer, sp1 is not)\n";
   if (!sp0) cout << "!sp0    : true\n"; else cout << "!sp0    : false\n";
   if (!sp1) cout << "!sp1    : true\n"; else cout << "!sp1    : false\n";

   cout << "\nExplicit equality test for null pointers (sp0 is a null pointer, sp1 is not)\n";
   if (sp0 == 0) cout << "sp0 == 0: true\n"; else cout << "sp0 == 0: false\n";
   if (0 == sp0) cout << "0 == sp0: true\n"; else cout << "0 == sp0: false\n";
   if (sp1 == 0) cout << "sp1 == 0: true\n"; else cout << "sp1 == 0: false\n";
   if (0 == sp1) cout << "0 == sp1: true\n"; else cout << "0 == sp1: false\n";

   cout << "\nExplicit inequality test for null pointers (sp0 is a null pointer, sp1 is not)\n";
   if (sp0 != 0) cout << "sp0 != 0: true\n"; else cout << "sp0 != 0: false\n";
   if (0 != sp0) cout << "0 != sp0: true\n"; else cout << "0 != sp0: false\n";
   if (sp1 != 0) cout << "sp1 != 0: true\n"; else cout << "sp1 != 0: false\n";
   if (0 != sp1) cout << "0 != sp1: true\n"; else cout << "0 != sp1: false\n";

   // delete is not allowed, as it should not be.
// delete sp0;

   return 0;
}
