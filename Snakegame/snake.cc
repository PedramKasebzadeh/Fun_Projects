#include<iostream>
#include <ncurses.h>
using namespace std;


class Snakegame{
    private:
    bool GameOver=true; // a boolean tro determain the state of the game
    int  board_width = 20; // game board width
    int  board_height= 40; // game board height 
    int x, y, xt, yt, dx, dy; // (x,y)snake head position,(xt,yt) snake tail,(dx,dy) diomond position
    enum Direction {STOP=0,UP,DOWN,LEFT,RIGHT};
    Direction dir;
    public:

    void setup()
    {
        initscr(); //  screen initialisation functions
        clear(); // clear the screen
        noecho();//  To suppress the automatic echoing of typed characters
        cbreak();//To disable the buffering of typed characters by the TTY driver and get "A character-AT-A-TIME" input; each key the user hits is returned immediately by getch(). Otherwise the keys hit by the user are queued until a newline is read. 
        keypad(stdscr, TRUE);//In order to capture special keystrokes like Backspace, Delete and the four arrow keys by getch()
        curs_set(0);
        
        GameOver = false;
        dir = STOP;
        x, xt = board_width/2;
        y, yt = board_height/2;
        dx = round(board_width%2);
        cout<< "setup executed!" << endl;

    }

    void Board()
    {

    }

    void input()
    {
    }

    void logic()
    {
    }
};


int main(){
    Snakegame game;
    game.setup();
    // while(!=GameOver)
    // {
    //   setup();
    //   Draw();
    //   input();  
    // }
    return 0;
}