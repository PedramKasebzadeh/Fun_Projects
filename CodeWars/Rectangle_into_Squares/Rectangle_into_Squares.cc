#include<iostream>
#include <vector>

std::vector<int> rect_to_square(int lng,int wdth){
    std::vector<int> res;
    if (lng==wdth) return res;
    while(lng != wdth){
      if (lng < wdth) std::swap(lng,wdth);
      res.push_back(wdth);
      lng= abs(lng-wdth);
    }
    res.push_back(wdth);
    return res;
}


int main(){
    rect_to_square(3,5);
    return 0;
}
