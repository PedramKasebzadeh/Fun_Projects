#include <iostream>
#include <string>
int main()
{
    std::string str="tuna";
    std::cout << str.substr(1,str.size()-2) << std::endl;
    return 0;
}