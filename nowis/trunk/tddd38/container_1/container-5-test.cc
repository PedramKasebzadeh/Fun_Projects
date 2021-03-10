/*
 * container-5-test.cc    Container Version 5
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

   cout << "Making a const copy of c1 in c2\n";
   const Container<Trace> c2(c1);

   cout << "c1.back() = " << c1.back() << '\n';
   cout << "Removing last element\n";
   c1.pop_back();
   cout << "c1.back() = " << c1.back() << '\n';
   cout << "Removing last element\n";
   c1.pop_back();
   cout << "c1.back() = " << c1.back() << '\n';
   cout << "Removing last element\n";
   c1.pop_back();
   cout << "c1.size()     = " << c1.size() << '\n';
   cout << "c1.capacity() = " << c1.capacity() << '\n';

   if (c1.empty())
      cout << "c1 is empty\n\n";
   else
      cout << "c1 is not empty\n\n";

   try
   {
      cout << "c1.back()\n";
      c1.back();
   }
   catch (const string& e)
   {
      cout << e << '\n';
   }

   cout << "\nOperating on c2 with accessor functions.\n";
   if (c2.empty())
      cout << "c2 is empty\n";
   else
      cout << "c2 is not empty\n";
   cout << "c2.size()     = " << c2.size() << '\n';
   cout << "c2.capacity() = " << c2.capacity() << "\n";
   cout << "c2.back() = " << c2.back() << '\n';

   return 0;
}
