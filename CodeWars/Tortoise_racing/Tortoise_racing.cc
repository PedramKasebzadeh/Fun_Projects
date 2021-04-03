#include<vector>
#include<iostream>

class Tortoise
{
public:
    static std::vector<int> race(int v1, int v2, int g){
        std::vector<int> res;
        if(v1 >= v2){res.push_back(-1);res.push_back(-1);res.push_back(-1);return res;}
        int sec= floor((double) g/(v2-v1) * 3600) ;
        std::cout << sec << std::endl;
        int s= sec % 60;
        int m= sec/60;
        int h= m/60;
        if(m>59){m= m%60;}
        res.push_back(h);
        res.push_back(m);
        res.push_back(s);
        return res;
    };
};

int main(){
    int v1= 80, v2= 91, g=37;
    std::vector<int> ou= Tortoise::race(v1,v2,g);
    std::cout<<ou[0] << ":"<<ou[1]<<":"<<ou[2] <<std::endl;
    return 0;
}