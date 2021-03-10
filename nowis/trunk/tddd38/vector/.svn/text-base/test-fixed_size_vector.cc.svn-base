/*
 * test-fixed_size_vector.cc
 */
#include "fixed_size_vector.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T, int N>
ostream& operator<<(ostream& os, const fixed_size_vector<T, N>& a)
{
   copy(a.begin(), a.end(), ostream_iterator<T>(os, " "));
   return os;
}

int main()
{
   cout << "fixed_size_vector<int, 10> a1;  // default constructor\n";
   fixed_size_vector<int, 10> a1;
   cout << "a1: " << a1 << '\n';
   cout << "a1.size(): " << a1.size() << '\n';
   cout << "a1.max_size(): " << a1.max_size() << '\n';
   cout << "a1.empty(): " << boolalpha << a1.empty() << '\n';

   cout << "\na1.fill(0);\n";
   a1.fill(0);
   cout << a1 << '\n';

   cout << "\nFilling a1 with values 1-10.\n";
   fixed_size_vector<int, 10>::iterator it = a1.begin();
   fixed_size_vector<int, 10>::iterator past_end = a1.end();

   int n = 0;
   for ( ; it != past_end; ++it)
      *it = ++n;
   cout << "a1: " << a1 << '\n';

   cout << "a1 in reverse order: ";
   for (fixed_size_vector<int, 10>::const_reverse_iterator rit = a1.crbegin();
	rit !=a1.crend();
	++rit)
   {
      cout << *rit << ' ';
   }
   cout << '\n';

   cout << "a1.front() = " << a1.front() << '\n';
   cout << "a1.back()  = " << a1.back() << '\n';

   cout << "a1[17]: " << a1[17] << '\n';
   cout << "a1[-17]: " << a1[-17] << '\n';

   try {
      cout << "a1.at(10): " << a1.at(10) << '\n';
   }
   catch (const exception& e) {
      cout << "exception caught: " << e.what() << '\n';
   }

   try {
      cout << "a1.at(-1): " << a1.at(-1) << '\n';
   }
   catch (const exception& e) {
      cout << "exception caught: " << e.what() << '\n';
   }

   cout << "a1.data(): " << a1.data() << '\n';
   cout << "*a1.data(): " << *a1.data() << '\n';
   cout << "*(a1.data() + 9): " << *(a1.data() + 9) << '\n';
   cout << "*(a1.data() + (a1.size() - 1) / 2): " << *(a1.data() + (a1.size() - 1) / 2) << '\n';

   cout << "\nfixed_size_vector<int, 10> a2(a1);  // copy contructor\n";   
   fixed_size_vector<int, 10> a2(a1);
   cout << "a2: " << a2 << '\n';
   
   cout << "Filling a2 with zeroes\n";
   a2.fill(0);
   cout << "a2: " << a2 << '\n';

   cout << "a2 = a1;  // copy assignment\n";   
   a2 = a1;
   cout << "a2: " << a2 << '\n';

   cout << "\nconst fixed_size_vector<int, 10> ac(a2);  // constant fixed_size_vector\n";   
   const fixed_size_vector<int, 10> ac(a2);
   cout << "ac: " << ac << '\n';
   cout << "ac in reverse order: ";
   for (fixed_size_vector<int, 10>::const_reverse_iterator crit = ac.rbegin();
	crit != ac.rend();
	++crit)
   {
      cout << *crit << ' ';
   }
   cout << '\n';
   cout << "ac.size(): " << ac.size() << '\n';
   cout << "ac.max_size(): " << ac.max_size() << '\n';
   cout << "ac.empty(): " << ac.empty() << '\n';
   

   cout << "\nfixed_size_vector<int, 0> a0;  // zero size fixed_size_vector\n";
   fixed_size_vector<int, 0> a0;
   cout << "a0: " << a0 << '\n';
   cout << "a0.size(): " << a0.size() << '\n';
   cout << "a0.max_size(): " << a0.max_size() << '\n';
   cout << "a0.empty(): " << a0.empty() << '\n';

   cout << "a0[0] = 4711;  // Illegal index!\n";
   a0[0] = 4711;
   cout << "a0[0]: " << a0[0] << '\n';
   cout << "a0.front(): " << a0.front() << '\n';
   cout << "a0.back() : " << a0.back() << '\n';

   try {
      cout << "a0.at(0): " << a0.at(0) << '\n';
   }
   catch (const exception& e) {
      cout << "exception caught: " << e.what() << '\n';
   }

   return 0;
}
