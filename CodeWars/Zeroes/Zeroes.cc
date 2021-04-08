#include <iostream>

long zeros(long n) {
    long count=0;
    for(int i =5;(n/i) >=1;i*=5) 
    {
        count+= n/i;
    }
  return count;
}
int main(){
    std::cout<< zeros(30) << std::endl;
    return 0;
}