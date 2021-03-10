#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int user_input;
    double real; 
    char character;
    string word;
//Ex1
// ex1.1 
    std::cout<< "Enter one integer: "<<std::endl;
    std:: cin >> user_input; 
    std:: cout << "You entered the number: " << user_input;
    cin.ignore(1000, '\n');
    cout << endl;
// ex1.2

    std::cout << "Enter four integers: "<<endl;
    std::cin >> user_input;
    std::cout << "You entered the numbers: " << user_input << " ";
    std::cin >> user_input;
    std::cout << user_input << " ";
    std::cin >> user_input;
    std::cout << user_input << " ";
    std::cin >> user_input;
    std::cout << user_input << "\n";
    cin.ignore(1000, '\n');
    cout << endl;
// ex1.3
     std::cout << "Enter one integer and one real number:"<<endl;
     cin >> user_input >> real; 
     cout<< "The real is:\t" << setprecision(4) << setw(12) <<real << endl; 
     cout << "The integer is: \t" << user_input << endl; 
     cin.ignore(1000, '\n');
     cout << endl;
// ex1.4
    cout << "Enter one real and one integer number:"<<endl;
    cin >> real >> user_input; 
    cout<< "The real is: " << setprecision(4)<<fixed << setfill('.') << setw(9)<<real << endl; 
    cout << "The integer is: "<< setfill('.') << setw(6) << user_input; 
    cin.ignore(1000, '\n');
    cout << endl;
// ex1.5
    cout << "Enter a character: "<<endl ; 
    cin >> character; 
    cout << "Youe entered: " << character;
    cin.ignore(1000, '\n');
    cout << endl;

// ex1.6
    cout << "Enter a word: " <<endl; 
    cin >> word; 
    cout << "The word " << word << " has " << word.size() <<" character(s).";
    cin.ignore(1000, '\n');
    cout << endl;
// ex1.6 
    cout << "Enter an integer and a word: "<<endl;
    cin >> user_input >> word; 
    cout << "You entered '" << user_input << "' and '"<< word<<"'.";
    cin.ignore(1000, '\n');
    cout << endl;
// ex1.7 
    cout << "Enter a character and a word: "<<endl; 
    cin >> character >> word ;
    cout << "You entered the string \""<< word << "\" and the character ’"<<character<<"’.";
    cin.ignore(1000, '\n');
    cout << endl;
// ex1.8 
    cout << "Enter a word and a real number: "<<endl;
    cin >> word >> real; 
    cout<< "You entered \"" <<word<<"\" and \""<<real<< "\"";
    cin.ignore(1000, '\n');
    cout << endl;
// ex1.9
    cout << "Enter a text-line: "<<endl;
    getline(cin, word);
    cout << "You entered: \"" << word<<"\""<<endl;
// ex1.10
    cout << "Enter a second line of text: "<< endl;
    getline(cin,word); 
    cout << "You entered: " << "\'"<< word << "\"";
    cout << endl;
// ex1.11
    cout << "Enter three words: " <<endl; 
    getline(cin,word);
    cout << "You entered: ’" <<word << "\'";
    cout << endl;
    return 0; 

}