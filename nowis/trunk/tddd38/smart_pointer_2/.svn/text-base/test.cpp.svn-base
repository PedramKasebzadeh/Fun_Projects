#include <iostream>
#include "smart_pointer.h"

using namespace std;
using namespace IDA_Smart_Pointer_II;

struct testouille {
  int a;
};

int main() {
  smart_pointer<testouille> t(new testouille);
  int *a = new int(42);
  smart_pointer<int> sp1(a);
  smart_pointer<int> nullSp;
  smart_pointer<int> sp2 = sp1;

  t->a = 8;
  cout << "Struct : " <<  t->a << endl;

  cout << *sp1 << "__" << nullSp.operator->() << "__" << *sp2 << endl;
  cout << sp1.operator->() << "__" << sp2.operator->() << endl;

  *sp1 = 14;
  cout << *sp1 << "__" << nullSp.operator->() << "__" << *sp2 << endl;

  const smart_pointer<int> csp(new int(7));
  cout << "*csp: " << *csp << endl;

  cout << "!nullSp : " <<  (!nullSp ? 'o' : 'n') << endl;

  if(!nullSp)
    cout << "Indeed, nullSp is null" << endl;
  if(!!sp1)
    cout << "Indeed, sp1 is not null" << endl;

  nullSp = csp;
  cout << *nullSp << endl;

  if(sp1 != sp2)
    cout << "sp1 != sp2" << endl;

  cout << "Deleting a" << endl;
  delete a;
  cout << "a : " << *a << endl;
  cout << "a : " << *sp1 << endl;

  return 0;
}

