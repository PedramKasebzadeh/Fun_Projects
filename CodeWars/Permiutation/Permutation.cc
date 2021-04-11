#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> permutations(string s) {
  vector<string> res;
  sort(s.begin(), s.end());
  do {
     res.push_back(s);
  } while (next_permutation(s.begin(), s.end()));
  return res;
}




int main(){
    vector<string> vec = permutations("aabb");
    for (std::vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
    std::cout << *i << ' ';
    return 0;
}