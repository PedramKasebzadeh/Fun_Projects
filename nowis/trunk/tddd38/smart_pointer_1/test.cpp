#include <iostream>
#include "smart_pointer.h"

using namespace std;
using namespace IDA_Smart_Pointer_I;

int main() {
  smart_pointer sp1(new int(42));
  smart_pointer nullSp;
  smart_pointer sp2 = sp1;

  cout << *sp1 << "__" << nullSp.operator->() << "__" << *sp2 << endl;
  cout << sp1.operator->() << "__" << sp2.operator->() << endl;

  *sp1 = 14;
  cout << *sp1 << "__" << nullSp.operator->() << "__" << *sp2 << endl;

  const smart_pointer csp(new int(7));
  cout << "*csp: " << *csp << endl;

  cout << "!nullSp : " <<  (!nullSp ? 'o' : 'n') << endl;

  nullSp = csp;
  cout << *nullSp << endl;

  if(sp1 != sp2)
    cout << "sp1 != sp2" << endl;

  return 0;
}

