/*
 * smart_pointer-test-const.cpp    Smart pointer II, Step 4.
 */
#include "smart_pointer.h"
#include <iostream>
#include <iomanip>
using namespace IDA_Smart_Pointer_II;
using namespace std;

int main()
{
   // Raw pointer tests to verify semantics.
   int*             p   = new int(1);
   const int*       pc  = new int(2);
   int* const       cp  = new int(3);
   const int* const cpc = new const int(4);

   // A pointer to non-constant may not point to a constant
   p = p;
// p = pc;
   p = cp;
// p = cpc;
   // A pointer to constant can safely point to both constants and non-constants
   pc = p;
   pc = pc;
   pc = cp;
   pc = cpc;
   // Constant pointers shall not be possible to modify
// cp = p;
// cp = pc;
// cp = cp;
// cp = cpc;
// cpc = p;
// cpc = pc;
// cpc = cp;
// cpc = cpc;

   cout << "Declaring different smart pointers regaring const:\n";
   cout << "smart_pointer<int>             sp(new int(5));\n";
   cout << "smart_pointer<const int>       spc(new int(6));\n";
   cout << "const smart_pointer<int>       csp(new int(7));\n";
   cout << "const smart_pointer<const int> cspc(new const int(8));\n";

   smart_pointer<int>             sp(new int(5));
   smart_pointer<const int>       spc(new int(6));
   const smart_pointer<int>       csp(new int(7));
   const smart_pointer<const int> cspc(new const int(8));

   // A smart pointer to non-constant may not point to a constant
   sp = sp;
// sp = spc;
   sp = csp;
// sp = cspc;
   // A smart pointer to constant can safely point to both constants and non-constants
   spc = sp;
   spc = spc;
   spc = csp;
   spc = cspc;
   // Constant smart pointers shall not be possible to modify
// csp = sp;
// cspc = sp;

   cout << "\nTesting operator* for different variants:\n";
   cout << "*sp  : " << *sp   << "\n";
   cout << "*spc : " << *spc  << "\n";
   cout << "*csp : " << *csp  << "\n";  // require const versionen of operator*
   cout << "*cspc: " << *cspc << "\n";  // require const versionen of operator*

   cout << "\nTesting operator-> for different variants:\n";
   cout << "*sp.operator->()  : " << *sp.operator->()   << "\n";
   cout << "*spc.operator->() : " << *spc.operator->()  << "\n";
   cout << "*csp.operator->() : " << *csp.operator->()  << "\n"; // require const versionen of operator->
   cout << "*cspc.operator->(): " << *cspc.operator->() << "\n"; // require const versionen of operator->

   cout << "\nnTesting operator-> for null smart pointer (constant smart pointer to constant):\n";
   const smart_pointer<const int> cspc0;
   // Segmentation fault, as it should:
//   cout << "*cspc0: " << *cspc0   << "\n";
   cout << "cspc0.operator->(): " << cspc0.operator->()   << "\n";

   // Should not be possible, and is not, with current implementaion
// csp = sp;
// *csp = 0;

   // raw pointers, so delete is of course allowed:
   delete p;
   delete pc;
   delete cp;
   delete cpc;
   
   return 0;
}
