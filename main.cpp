#include <iostream>
#include <vector>
using namespace std ; 


void print_vector(vector<int> vec){
  vec.push_back(12);
  for(int i =0; i < vec.size() ; i++){
    cout << vec[i] << '\t';
  }
}
 
int main()
{
  vector<int> data = {1,2,3};
  cout << data.size() <<endl;
  print_vector(data);
}




// int main()
// {
//   const std::string& numbers = "8 3 -5 42 -1 0 0 -9 4 7 4 -4";
//   std::istringstream in(numbers);
//   const auto [min, max] = std::minmax_element(std::istream_iterator<int>(in), std::istream_iterator<int>());
//   std::ostringstream out;
//   out << *max << ' ' << *min;
//   return out.str();
// }

