#include<iostream>
#include <string>
#include<algorithm>
#include <map>

// template<typename K, typename V>
// void print_map(std::map<K,V> const &m)
// {
//     for (auto const& pair: m) {
//         std::cout << "{" << pair.first << ": " << pair.second << "}\n";
//     }
// }
 

typedef unsigned long long ull;
bool isPrime(ull n) {
  if (n <= 1 ) return false; if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)  if (n % i == 0 || n % (i + 2) == 0) {return false;}
   return true;
}

std::string decomp(int n) {
    ull factorial = 1;
    int i=1;
    std::string str;
    while(i<=n) {
            factorial *= i;
            i++;
        }
    i =2;
    std::map<int,int> primes; 
    while(!isPrime(factorial)){
        if(factorial%i != 0){
        i++;
        } else {
        factorial = factorial / i;
        primes[i]++;
        }
    }
    primes[factorial]++;
    for (const auto& p : primes) {
        if(p.second<2){
    str +=  std::to_string(p.first) + " * "; 
        } else {
    str +=  std::to_string(p.first) + "^"+  std::to_string(p.second) + " * ";
        }
}
    str = str.substr(0, str.size()-3);
    std::cout << str << std::endl;
     return str;
}

int main(){
    decomp(12);
    return 0;
}