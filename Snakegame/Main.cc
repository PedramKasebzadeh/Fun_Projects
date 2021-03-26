#include <cstdlib>
#include <ncurses.h>
#include <iostream>


bool GameOver;

// Initialize the size of the game boardconst int width=20;
const int width=20;
const int height=20;
// Coordinates for snake and fruit and a possible score 
int x,y,xd,yd,score;
int xtail[100], ytail[100];
int ntail;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};// Possible directions snake can go
eDirection dir;

void Setup()
{
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);

    GameOver= false;
    dir= STOP ; // Start without any Directions
    // Start at the middle of the game board
    x= width/2;
    y= height/2; 
    // Diamonds at a random place in the game board 
    xd = rand() % width;// gives a random number in the width range(0 to width-1).
    yd = rand() % height;
    score=0;
}

void Board(){
//screen clear for every instance to transform into animation.
clear();
    for (int i = 0; i < width+2; i++)
        mvprintw(0,i,"#");
    for (int i = 0; i< height+2; i++)
    {
        for (int j = 0; j < width+2; j++)
        {
            if (i == 0 || i== width+1) // top and bottom
                mvprintw(i,j,"#"); 
            else if (j == 0 || j== height+1) // side borders 
                mvprintw(i,j,"#");
            else if (i == y && j== x) // Head of snake
                 mvprintw(i,j,"Q");  
            else if (i == yd && j== xd) // Diomand
                     mvprintw(i,j,"*"); 
                     else
                {      
                    for ( int k = 0; k < ntail; k++)
                    {
                        if(xtail[k]==j && ytail[k]==i)
                        {
                            mvprintw(i,j,"o");
                        }  
                    } 
                }  
          }
    }
    mvprintw(height+5,0,"Score is: %d", score);
    refresh();
}

void Input()
{
     keypad(stdscr, true);
  halfdelay(1);
  int c = getch();
  switch(c)
  {
    case KEY_LEFT:
      dir = LEFT;
      break;
    case KEY_RIGHT:
      dir = RIGHT;
      break;
    case KEY_UP:
      dir = UP;
      break;
    case KEY_DOWN:
      dir = DOWN;
      break;
    case '113': // 113 represents q for quit 
      GameOver = true;
      break;
    }
}

void logic()
{
    int prevX = xtail[0];
  int prevY = ytail[0];
  int prev2X, prev2Y;
  xtail[0] = x;
  ytail[0] = y;
  for (int i = 1; i < ntail; i++)
  {
    prev2X = xtail[i];
    prev2Y = ytail[i];
    xtail[i] = prevX;
    ytail[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y;
  }
    switch(dir)
  {
    case LEFT:
      x--;
      break;
    case RIGHT:
      x++;
      break;
    case UP:
      y--;
      break;
    case DOWN:
      y++;
      break;
    default:
      break;
  }
    if(x > width || x < 1 || y < 1 || y > height)
    GameOver = true; 
    if(x == xd && y==yd) 
    {
        score++ ;
        xd = (rand() % width)+1;
        yd = (rand() % height)+1;
        ntail++;
    }
    for (int i=0 ; i < ntail ; i++)
        if(xtail[i]==x && ytail[i]==y)
            GameOver=true;
}

int main(){
    Setup();
    Board();
   while (!GameOver)
    {
        Board();
        Input();
        logic();
    }
    return 0;
}