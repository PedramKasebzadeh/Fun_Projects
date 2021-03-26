#include <vector>
#include <iostream>
std::vector<int> vec = {1,2,2};
int main()
{   
    int temp=0;
    for(int i :vec)
    {
        temp += i*i;
    }
    std::cout << temp << std::endl;
    return 0;
}
/* 
// Submitted version 
#include <vector>

int square_sum(const std::vector<int>& numbers)
{
    int temp=0;
    for(int i:numbers)
      temp+= i*i;
    return temp;
}
*/

// Smarte version  by siebenschlaefer
/*
#include <numeric>
#include <vector>

int square_sum(const std::vector<int>& numbers)
{
    return std::accumulate(numbers.begin(), numbers.end(), 0, [](int a, int b) {return a + b * b;});
}
*/