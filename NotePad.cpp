#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

// Wirte a file! 

// int main(){
//     std::string FileName;
//     std::cout << "What should we call this file?" << std::endl;
//     std::cin >> FileName;
//     std::ofstream file (FileName); // if you want too add the names to the file you already have add this argument here: std::ios::app
//     std::vector<std::string> names;
//     std::string UserInput;
//     std::cout << "Who is in it?(press q when you're done!)" << std::endl;
//     do
//     { 
//         std::cin >> UserInput;
//         names.push_back(UserInput);
//     } while (UserInput != "q");
//     names.pop_back(); // removing the added q for quiting!
//     for (std::string n :names)
//     {
//         file << n << std::endl;
//         }
//     return 0;
// }

//read from a file !

int main(){
    std::ifstream file ("Friends");
    std::vector<std::string> names; 

    std::string input; 
    while (file >> input)
    {
        names.push_back(input);
    }
    for (std::string name : names)
    {
        std::cout << name <<std::endl;
    }
    return 0;
}
