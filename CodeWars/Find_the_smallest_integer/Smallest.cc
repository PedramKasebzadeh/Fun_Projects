#include <vector>
#include <iostream>
std::vector<int> vec = {100,10,2};
int main()
{   
    int smallest= vec[0];
    for(int i=1; i<vec.size();i++)
    {
        if(smallest>vec[i])
            smallest=vec[i];
    }
    std::cout <<smallest;
    return 0;
}