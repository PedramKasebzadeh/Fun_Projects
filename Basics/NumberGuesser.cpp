#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std; 

void save_score(std::vector<int> guesses)
{
    std::ifstream input("BestScore.txt");
    if(!input.is_open()){
        std::cout << "The file is broken\n";
        return;
    }
    int best_score; 
    input >> best_score; 
    std::ofstream output ("BestScore.txt");
    if(!output.is_open()){
        std::cout << "The file is broken\n";
        return;
    }
    output << ((guesses.size()< best_score) ? guesses.size(): best_score);
}
void print_vector(vector <int> vec){
    for (int i = 0 ; i < vec.size(); i++)
    {
        cout << vec[i] << "\t" ;
    }
    cout << endl;
}
void play_game() {
    vector <int> guesses; 
    int random  = rand() % 251;
    cout << random << endl;
    cout << "Guess a number"  << endl;
    while(true){
        int guess;
        cin >> guess; 
        guesses.push_back(guess);
        if (guess == random){
            cout << "Well done!" << endl;
            break;
        } else if( guess > random) {
            cout << "You guessed too high" << endl;
        } else{
            cout << "Too Low!" << endl;
        }
    }
    save_score(guesses);
    print_vector(guesses);
} 
int main(){
    srand(time(NULL)); // To get a random number based on CPU time 
    int choice; 
    do{
    cout << "0. Quit \n1. Play Game" << endl;
    cin >> choice; 
    switch (choice)
    {
    case 0:
        cout << "Scared?" << endl;
        return 0;
    case 1:
        play_game();
        break;
    // default:
    //     cout << "What the hell" << endl;
    //     break;
    }
    } while (choice !=0);
    
    return 0;
}

// void print_array(int array[],int size){
//     for (int i = 0 ; i < size; i++)
//     {
//         cout << array[i] << "\t" ;
//     }
//     cout << endl;
// }

// int main(){
//     const int Size = 10; 
//     int guesses[Size];
//     for (int i = 0; i < Size; i++){
//         cin >> guesses[i];
//     }
//     print_array(guesses, Size);
//     return 0 ;
// } 