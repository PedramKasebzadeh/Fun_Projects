#include <vector>
#include<algorithm>
#include <iostream>


int main(){
  std::vector<int> output;
  int x=1,n= 10;
  std::generate(output.begin(),output.end(),[k=0,&x]() mutable {return k+=x;});
  return 0;
}
//  std::vector<int> expected = {1,2,3,4,5,6,7,8,9,10};



