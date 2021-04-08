#include<iostream>
#include<vector>
#include <numeric>
#include <cstdint>
using namespace std;

typedef unsigned long long ull;
class SumFct
    {
    public:
  static ull perimeter(ull n){
    ull i=2;
    std::vector<int> count ={1,1};
        while(i<n+1){
            count.push_back(count[i-2] + count[i-1]);
            i++;
       }
       ull res = std::accumulate(count.begin(), count.end(),0LL);// accumulate pitfall ! intial value sets the type!
       return res;
   };
};



int main(){
    std::cout<< SumFct::perimeter(43) <<std::endl;
    return 0;
}