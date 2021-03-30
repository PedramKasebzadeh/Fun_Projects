#include <iostream>
#include <map>
using namespace std;
size_t duplicateCount(const char* in)
{
    std::map<char,int> input; // initializing a map
    for(int i=0; in[i]!=0; i++){
        input[std::tolower(in[i])]++; // lower casing and mapping to "input" 
    }
    // now sum up all the values more than 1! 
    return count_if(input.begin(),input.end(),[](auto &i) {return i.second>1?true:false;});
}
int main(){
    cout << duplicateCount("aabbcc") << endl;
    return 0;
}
