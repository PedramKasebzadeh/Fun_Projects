#include<algorithm>
#include <map>
#include <string>
#include<vector>
#include<iostream>


template<typename K, typename V>
void print_map(std::map<K,V> const &m)
{
    for (auto const& pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
};


std::vector<int> Findprimes(int n)
{
    std::vector<int> v;
    v.push_back(2);
    v.push_back(3);
	for (int i=2; i<=n; i++) 
        for (int j=2; j*j<=i; j++)
        {
            if (i % j == 0) 
                break;
            else if (j+1 > sqrt(i)) {
                v.push_back(i);
            }
        } 
    return v;
}


std::string decomp(int n) {
  std::string str;
  std::vector<int> v =Findprimes(n);
  std::cout << v[1] << std::endl;
  std::map<int,int> primes; 
    for(int i=1; i <= n ; i++){
      for(int p : v){
          int temp=i;
          while(temp%p==0){
              primes[p]++;
              temp = temp/p; 
    }   }   }
  for (const auto& p : primes) {
        if(p.second<2){
    str +=  std::to_string(p.first) + " * "; 
        } else {
    str +=  std::to_string(p.first) + "^"+  std::to_string(p.second) + " * ";
        }
}
  str = str.substr(0, str.size()-3);
  return str;
}


int main(){
    std::cout<<decomp(17)<<std::endl;
    return 0;
}