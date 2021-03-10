/*
 * smart_pointer-test-compare-more.cpp    Smart pointer II, Step 3.
 *
 * Testing for polymorphic types.
 */
#include "smart_pointer.h"
#include <iostream>
#include <iomanip>
using namespace IDA_Smart_Pointer_II;
using namespace std;

struct Base {};
struct Derived : Base {};

int main()
{
   smart_pointer<Base>    spb(new Base);
   smart_pointer<Derived> spd(new Derived);

   cout << "\nComparing two different smart pointers using == and !=\n";
   if (spb == spb) cout << "spb == spb: true\n"; else cout << "spb == spb: false\n";
   if (spb == spd) cout << "spb == spd: true\n"; else cout << "spb == spd: false\n";
   if (spb != spb) cout << "spb != spb: true\n"; else cout << "spb != spb: false\n";
   if (spb != spd) cout << "spb != spd: true\n"; else cout << "spb != spd: false\n";

   Base*    pb = new Base;
   Derived* pd = new Derived;

   cout << "\nJComparing smart pointer abd raw pointer using == och !=\n";
   if (spb == pb) cout << "spb == pb: true\n"; else cout << "spb == pb: false\n";
   if (spb == pd) cout << "spb == pd: true\n"; else cout << "spb == pd: false\n";
   if (spb != pb) cout << "spb != pb: true\n"; else cout << "spb != pb: false\n";
   if (spb != pd) cout << "spb != pd: true\n"; else cout << "spb != pd: false\n";
   cout << '\n';
   if (pd == spb) cout << "pd == spb: true\n"; else cout << "pd == spb: false\n";
   if (pd == spd) cout << "pd == spd: true\n"; else cout << "pd == spd: false\n";
   if (pd != spb) cout << "pd != spb: true\n"; else cout << "pd != spb: false\n";
   if (pd != spd) cout << "pd != spd: true\n"; else cout << "pd != spd: false\n";

   return 0;
}
