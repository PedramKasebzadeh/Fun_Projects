#include <sstream>
#include <vector>
#include <math.h>
#include <iostream>
#include <numeric>
using namespace std;

class Fracts
{

public:
    static int GCD(int a,int b){
         if(b > 0){return GCD(b,a%b);}else{return a;}
    }
    static int LCM(int a,int b){
    return (a*b)/GCD(a,b);
    }
    static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst){
    std::stringstream ss;
    std::vector<int> denoms;
    for(int i = 0; i<lst.size();i++){
    denoms.push_back(lst[i][1]);}
    int denom = std::accumulate(denoms.begin(), denoms.end(), 1, LCM);
    for(int i = 0; i<lst.size();i++)
    { ss << "("<< (denom*lst[i][0])/lst[i][1]<< ","<< denom<< ")";}
    return ss.str();
    };
};
int main(){
    std::vector<std::vector<unsigned long long>> r1 = { {1, 2}, {1, 3}, {1, 4} };
    //std::cout << r1.size() << std::endl;
    std::cout << Fracts::convertFrac(r1) << std::endl;
    return 0;
}