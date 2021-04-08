#include <sstream>
#include <map>
#include <iostream>
#include <random>


class SnakesLadders
{

  private:
  std::map<int, int> board = { {2,38}, {7,14}, {8,31}, {15, 26}, {16, 6},
  {21, 42}, {28, 84}, {36, 44}, {46, 25}, {49, 11}, {51, 67}, {62, 19},
  {64, 60}, {71, 91}, {74, 53}, {78, 98}, {87, 94}, {89, 68}, {92, 88},
  {95, 75}, {99,80} };
  int players[2] = {0, 0}; // index 0 is player1 -- index 1 is player2
  int whosturn = 0; // 0 is p1 turn 1 is p2 turn
  public:

    SnakesLadders(){};
    std::string play(int die1, int die2);
    int get_winner();
};
std::string SnakesLadders::play(int die1, int die2)
{
  std::cout << "Player" << whosturn + 1 << "rolled: " << die1 << " :: " << die2 << "\n";
  std::ostringstream o; // to format the return string
  if (players[0] == 100 || players[1] == 100)
    return "Game over!";
  players[whosturn] += die1 + die2;
  if (players[whosturn] > 100)
    players[whosturn] = 100 - (players[whosturn] - 100);
  if (players[whosturn] == 100)
    o << "Player " << whosturn + 1 << " Wins!";
  else {
    auto slide = board.find(players[whosturn]); // auto is an std::map<int, int>::iterator;
    if (slide != board.end())
      players[whosturn] = slide->second;
    o << "Player " << whosturn + 1 << " is on square " << players[whosturn];
  }

  if (die1 != die2)
    whosturn = (whosturn == 0) ? 1 : 0;
  return o.str();
};

int main(){
    SnakesLadders game = SnakesLadders();
    std::cout<<game.play(1,1)<<std::endl;
    std::cout<<game.play(1,5)<<std::endl;
    std::cout<<game.play(6,2)<<std::endl;
    std::cout<<game.play(1,1)<<std::endl;
    return 0;
}