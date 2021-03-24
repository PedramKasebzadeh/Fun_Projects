#include <iostream>
using namespace std;
bool GameOver;

// Initialize the size of the game board
const int width=20;
const int height = 20; 
// Coordinates for snake and fruit and a possible score 
int x,y,fx,fy, score; 
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN}; // Possible directions snake can go
eDirection dir;


void Setup()
{
    GameOver = false;
    dir= STOP; // Start without any Directions
    // Start at the middle of the game board
    x= width/2;
    y= height/2; 
    // Fruit at a random place in the game board 
    fx=  rand() % width; // gives a random number in the width range(0 to width-1).
    fy=  rand() % height;
    score = 0;
}

#include <ncurses.h> // input output

void Board()
{
    clear(); // clean the screen(Terminal)
    // Display top border of the map
    for(int i=0; i < width; i++)
    {
        cout<<"#";
    }
    cout<<endl;
    // print the map 
    for (int i =0; i < height;i++)
    {
        for(int j=0; j<width;j++)
        {
            if(j==0 || j==width-1)// print walls
            {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout<<endl;

    }
    // for (int i=0; i<height;i++)
    // {
    //     cout<<"#";
    //     cout<<endl;
    // }

}
void Input()
{

}
void logic()
{

}
int main(){
    Setup();
    while (!GameOver)
    {
        Board();
        
        Input();

        logic();
    }
    
    return 0;
}