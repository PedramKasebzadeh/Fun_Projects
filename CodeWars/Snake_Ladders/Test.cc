#include<iostream>
#include<map>
using namespace std;


class Player
{
    public:
    std::string name;
    static int pos;
};

int main(){
    Player(p1);
    p1.name= "Player 1";
    p1.pos= 0;
    //Player p2 = {"Player 2",0};
    Player * player=&p1;
    cout << player->name << "  " << player->pos << endl;
    return 0;
}



    // map<int,int> snakemap;
    // snakemap.insert({16,6});
    // snakemap.insert({23,4});
    // snakemap.insert({16,12});
    // snakemap.insert({26,63});
    // int temp = 23;


    // if ( snakemap.find(temp) != snakemap.end() ) {
    //     cout <<  snakemap[temp] << endl;
    // } 
    //cout << snakemap[16] <<endl;