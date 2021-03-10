/*
 * container-2-test.cc    Container Version 2
 */
#include <iostream>
#include <string>
#include "Container.h"
using namespace std;

int main()
{
   cout << "c1 is default initialized.\n";
   Container<string> c1;  // default constructor
   cout << "c1.size()     = " << c1.size() << '\n';
   cout << "c1.capacity() = " << c1.capacity() << "\n\n";

   // Construction with size (elements are default initialized)
   cout << "c2 is initialized with 100.\n";
   Container<string> c2(100);
   cout << "c2.size()     = " << c2.size() << '\n';
   cout << "c2.capacity() = " << c2.capacity() << "\n\n";

   cout << "c3 is initialized with c2.\n";
   Container<string> c3(c2);  // copy constructor
   cout << "c3.size()     = " << c3.size() << '\n';
   cout << "c3.capacity() = " << c3.capacity() << "\n\n";   
   
   cout << "c3 = c1;\n";
   c3 = c1;  // copy assignment operator
   cout << "c3.size()     = " << c3.size() << '\n';
   cout << "c3.capacity() = " << c3.capacity() << "\n\n";   

   cout << "c3 = c2;\n";
   c3 = c2;
   cout << "c3.size()     = " << c3.size() << '\n';
   cout << "c3.capacity() = " << c3.capacity() << "\n\n";   

   return 0;
}
