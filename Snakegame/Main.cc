#include <cstdlib>
#include <ncurses.h> // input output
#include <iostream>


#define KEY_UP 0403 // 
#define KEY_DOWN 0402 //
#define KEY_LEFT 0404 // 
#define KEY_RIGHT 0405 // 

using namespace std;

bool GameOver;

// Initialize the size of the game board
const int width=20;
const int height = 20; 
// Coordinates for snake and fruit and a possible score 
int x,y,fx,fy, score; 
int tailX[100], tailY[100];
int nTail;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN}; // Possible directions snake can go
eDirection dir;


void Setup()
{
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);

    GameOver = false;
    dir= STOP ; // Start without any Directions
    // Start at the middle of the game board
    x= width/2;
    y= height/2; 
    // Fruit at a random place in the game board 
    fx=  rand() % width; // gives a random number in the width range(0 to width-1).
    fy=  rand() % height;
    score = 0;
}


void Board() {
//screen clear for every instance to transform into animation.
 clear();
    for(int i = 0; i < width+2; i++)
        mvprintw(0,i,"+");
    for(int i = 0; i < height+2; i++)
    {
        for(int j = 0; j < width+2; j++)
        {
            if (i == 0 || i == 21)
                mvprintw(i, j, "+");
            else if (j == 0 || j == 21)
                mvprintw(i, j, "+");
            else if (i == y && j == x)
                mvprintw(i, j, "O");
            else if(i == fy && j == fx)
                mvprintw(i, j, "Q");
                  else
            {
              for(int k = 0; k < nTail; k++)
              {
                if (tailX[k] == j && tailY[k] == i)

                {
                  mvprintw(i, j, "o");
                }
              }
            }      
        }
    }
    mvprintw(23, 0, "Score %d", score);
    refresh();
}


void Input(){
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
    case 'Q':
      GameOver = true;
      break;
    }
}
void logic()
{
 int prevX = tailX[0];
  int prevY = tailY[0];
  int prev2X, prev2Y;
  tailX[0] = x;
  tailY[0] = y;
  for (int i = 1; i < nTail; i++)
  {
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
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
  if(x == fx && y == fy)
  {
    score++;
    fx = (rand() % width)+1;
    fy = (rand() % height)+1;
    nTail++;
  }
  for (int i = 0; i < nTail; i++)
    if (tailX[i] == x && tailY[i] == y)
    {
      GameOver = true;
    }
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