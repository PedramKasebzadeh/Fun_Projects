#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>

int main()
{   
    std::vector<int> lengths;
    std::string shortest_word="Justalongwordfornoreason"; 
    std::string longest_word;
    std::string word;
    std::ifstream input("Data.txt");
    while(input >> word)
    {
        if (word.size()>longest_word.size())
        {
            longest_word = word;
        } else if(word.size()<shortest_word.size())
        {
            shortest_word = word;
        }
        lengths.push_back(word.size());    
    }
    if (lengths.size()>1)
        {
            std::cout << "There are "<< lengths.size() <<" words in the file."<<std::endl;
            std::cout <<"The shortest word was \""<<shortest_word<<"\" with 1 character(s)."<<std::endl;
            std::cout <<"The longest word was \""<<longest_word<<"\" with "<<longest_word.size()<<" character(s)." <<std::endl;
            std::cout <<"The average length was "<<std::setprecision(2)<<std::fixed<< std::accumulate( lengths.begin(), lengths.end(), 0.0)/lengths.size()<<" character(s)." << std::endl;
        } else {
            std::cout << "WARNING: Hmmm, an empty file?"<<std::endl;
        }
     return 0;  
}