/*
 * container-4-test.cc    Container Version 4
 *
 * Tracer helper class is used to trace use of operations on Tracer objects,
 * i.e. to find out the requirements Container puts on the contained objects.
 * To not get misleading traces, the test program as such must no require any
 * temporary objects of type Tracer.
 */
#include <iostream>
#include <string>
#include "Container.h"
#include "Tracer.h"
using namespace std;

typedef Tracer<string> Trace;

int main()
{
   Trace::on();

   Container<Trace> c1;
   cout << "c1.size()     = " << c1.size() << '\n';
   cout << "c1.capacity() = " << c1.capacity() << '\n';

   if (c1.empty())
      cout << "c1 is empty\n\n";
   else
      cout << "c1 is not empty\n\n";

   cout << "c1.push_back(one)\n";
   Trace one("one");
   c1.push_back(one);
   cout << "c1.size()     = " << c1.size() << '\n';
   cout << "c1.capacity() = " << c1.capacity() << "\n\n";

   cout << "c1.push_back(two)\n";
   Trace two("one");
   c1.push_back(two);
   cout << "c1.size()     = " << c1.size() << '\n';
   cout << "c1.capacity() = " << c1.capacity() << "\n\n";

   cout << "c1.push_back(three)\n";
   Trace three("three");
   c1.push_back(three);
   cout << "c1.size()     = " << c1.size() << '\n';
   cout << "c1.capacity() = " << c1.capacity() << '\n';

   if (c1.empty())
      cout << "c1 is empty\n\n";
   else
      cout << "c1 is not empty\n\n";

   cout << "c1.pop_back() = " << c1.pop_back() << '\n';
   cout << "c1.size()     = " << c1.size() << "\n\n";
   cout << "c1.pop_back() = " << c1.pop_back() << '\n';
   cout << "c1.pop_back() = " << c1.pop_back() << '\n';
   cout << "c1.size()     = " << c1.size() << '\n';

   if (c1.empty())
      cout << "c1 is empty\n\n";
   else
      cout << "c1 is not empty\n\n";

   try
   {
      cout << "c1.pop_back()\n";
      c1.pop_back();
   }
   catch (const string& e)
   {
      cout << e << '\n';
   }

   return 0;
}
