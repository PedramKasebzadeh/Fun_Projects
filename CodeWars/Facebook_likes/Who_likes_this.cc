#include<iostream>
#include<vector>
#include<string>
using namespace std;

string likes(const vector<string> &names)
{
         std::string res;
    int size= names.size();
        switch (size)
        {
        case 0:
            res = "no one likes this";
            break;
        case 1:
            res += names[0]+" likes this";
            break;
        case 2:
            res += names[0]+" and "+ names[1] +" like this";
            break;
        case 3:
            res += names[0]+ ", "+ names[1]+" and " + names[2] + " like this";
            break;
        default:
            res += names[0]+ ", " + names[1]+ " and "+ std::to_string(size-2)+ " others like this";
            break;
        };        
    return res;
};
int main(){
    vector<string> test;
    test.push_back("Alex");
    test.push_back("Jacob");
    test.push_back("Mark");
    test.push_back("Max");
    cout << likes(test) << endl;
    return 0;
}