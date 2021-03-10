/*
 * smart_pointer-function-calls.cpp    Smart poiner II, Step 1.
 */
#include "smart_pointer.h"
#include "Tracer.h"
#include <iostream>
#include <iomanip>
using namespace IDA_Smart_Pointer_II;
using namespace std;

typedef APiCPP_Tracer::Tracer<int> Trace;

// Function taking a smart pointer as a value parameter (copy in).
template<typename T>
void fun1(smart_pointer<T> sp)
{
   cout << "  ENTERING fun1(smart_pointer<T>)\n";
   cout << "   Creating local object initialized by parameter.\n";
   smart_pointer<T> local(sp);
   cout << "  LEAVING fun1(smart_pointer<T>)\n";
}

// Function taking a smart pointer as a reference parameter.
template<typename T>
void fun2(smart_pointer<T>& sp)
{
   cout << "  ENTERING fun2(smart_pointer<T>&)\n";
   cout << "   Creating local object initialized by parameter.\n";
   smart_pointer<T> local(sp);
   cout << "  LEAVING fun2(smart_pointer<T>&)\n";
}

// Function taking a smart pointer as a const reference parameter.
template<typename T>
void fun3(const smart_pointer<T>& sp)
{
   cout << "  ENTERING fun3(const smart_pointer<T>&)\n";
   cout << "   Creating local object initialized by parameter.\n";
   smart_pointer<T> local(sp);
   cout << "  LEAVING fun3(const smart_pointer<T>&)\n";
}

// Function returning a smart pointer. This will easily cause problems, since
// a temporary, at least semantically, is used in returning the smart_pointer,
// and one often in the callee would like to use this object to initialize
// or assign another smart_pointer. Since the copy constructor and the copy
// assignment operator must have a non-const parameter if the smart pointer
// implements destructive copy, they can not be used, since a temporary only
// can be bound to a reference, if the reference is const.
template<typename T>
smart_pointer<T> fun4()
{
   cout << "  ENTERING fun4()\n";
   cout << "   Creating local object, which is returned.\n";
   smart_pointer<T> local(new T);
   cout << "  LEAVING fun4()\n";
   return local;
}

int main()
{
   Trace::on();

   cout << "Declaring smart pointer:\nsmart_pointer<Trace> sp1(new Trace(1));\n";
   smart_pointer<Trace> sp1(new Trace(1));
   cout << "\nCalling function: fun1(sp1):\n";
   fun1(sp1);
   cout << "\nBack from fun1()\n";

   cout << "\nDeclaring smart pointer:\nsmart_pointer<Trace> sp2(new Trace(2));\n";
   smart_pointer<Trace> sp2(new Trace(2));
   cout << "\nCalling function: fun2(sp2):\n";
   fun2(sp2);
   cout << "\nBack from fun2()\n";

   cout << "\nDeclaring smart pointer:\nsmart_pointer<Trace> sp5(new Trace(3));\n";
   smart_pointer<Trace> sp5(new Trace(3));
   cout << "\nCalling function: fun3(sp5):\n";
   fun3(sp5);
   cout << "\nBack from fun3()\n";

   cout << "\nDeclaring smart pointer:\nsmart_pointer<Trace> sp4;\n";
   smart_pointer<Trace> sp4;
   cout << "\nCalling function: sp4 = fun4<Trace>():\n";
   sp4 = fun4<Trace>();
   cout << "\nBack from fun4()\n\n";

   return 0;
}
