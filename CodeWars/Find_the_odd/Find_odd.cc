#include <vector>
# include <iostream>
#include <map>
using namespace std;


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


/* a cool approach 

#include <functional>
#include <numeric>
#include <vector>

int findOdd(const std::vector<int>& numbers) {
  return std::accumulate(numbers.cbegin(), numbers.cend(), 0, std::bit_xor<>());
}

*/

/* OUT OF THE BOX! 
#include <vector>

int findOdd(const std::vector<int>& numbers){
  int result = 0;
  for(auto& num : numbers){
    result = result ^ num;
    
  }
  return result;
}
*/