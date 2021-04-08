#include<iostream>
#include<map>
#include <algorithm>

bool scramble(const std::string& s1, const std::string& s2){
  std::map<char,int> s2m;
  std::map<char,int> s1m;
  for(char c: s1){
      s1m[c]++;
  }
  for(char c: s2){
        s1m[c]--;
        if(s1m[c]<0){
            return false;
        }
    }
    return true;
}

int main(){
    std::cout <<scramble("cedewaraaossoqqyt", "codewars") << std::endl;
    return 0;
}