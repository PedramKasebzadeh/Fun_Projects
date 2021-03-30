#include <vector>
# include <iostream>
#include <map>
int findOdd(const std::vector<int>& numbers){
  std::map<int,int> input; // initialize the map
  for(int i : numbers){
      input[i]++; //  let's see what happend how often!
  }
    for (auto t:input){
       if(t.second%2 !=0){ // if it was even, it would be zero! 
           return t.first;
       }
    }
  return 0;
}
int main(){
    const std::vector<int>& numbers{1,1,2,2,3,4,4};
     std::cout << findOdd(numbers) << std::endl;
    return 0;
}


/* a cool approach 

#include <functional>
#include <numeric>
#include <vector>

int findOdd(const std::vector<int>& numbers) {
  return std::accumulate(numbers.cbegin(), numbers.cend(), 0, std::bit_xor<>());
}

*/