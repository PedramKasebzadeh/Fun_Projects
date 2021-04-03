#include<vector>
#include<iostream>

class Tortoise
{
public:
    static std::vector<int> race(int v1, int v2, int g){
        if(v1 >= v2) return {-1,-1,-1};
        int sec= floor((double) g/(v2-v1) * 3600) ;
        return {sec/3600, (sec/60)%60, sec%60 };
    };
};

int main(){
    int v1= 80, v2= 91, g=37;
    std::vector<int> ou= Tortoise::race(v1,v2,g);
    std::cout<<ou[0] << ":"<<ou[1]<<":"<<ou[2] <<std::endl;
    return 0;
}