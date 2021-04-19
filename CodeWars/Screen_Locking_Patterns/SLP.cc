#include<iostream>
#include <map>
#include<vector>
using namespace std;

struct compare
{
    char key;
    compare(char const &i): key(i) {}
 
    bool operator()(char const &i) {
        return (i == key);
    }
};

struct Nodes
    {
    vector<char> direct;
    vector<std::tuple<char,char>> indirect;
    };
typedef std::map<char,Nodes> Graphs;
Graphs graph;

vector<char> possibilities(vector<char> visited){
    vector<char> possible_next_moves;
    char current_node = visited.back(); //D
    for(const auto &i : graph[current_node].direct)
        if (!std::any_of(visited.begin(), visited.end(), compare(i))) {
            possible_next_moves.push_back(i);
    }
    for(const auto &i : graph[current_node].indirect)
        if(std::any_of(visited.begin(), visited.end(),compare(get<0>(i))) && !std::any_of(visited.begin(), visited.end(),compare(get<1>(i)))){
            possible_next_moves.push_back(get<1>(i));
        };
        return possible_next_moves;
}


int combinations(vector<char> visited,char current_node, int length){
    int result=0;
    if (length == 1)
        return 1;
    visited.push_back(current_node);
    vector<char>next_step = possibilities(visited);
    length--;
    for(char node : next_step){
            result += combinations(visited, node, length);
    }
    return result;
}

unsigned int countPatternsFrom(char firstDot, unsigned short length) {
    if (length<0 || length > 10 ){
        return 0;
        }else {
            vector<char> visited;
            return combinations(visited,firstDot, length);
        }
}


int main()
{

// A
Nodes nodeA;
vector<char> directA{'B', 'D', 'E', 'F', 'H'};
vector<std::tuple<char,char>> indirectA;
indirectA.push_back(make_tuple('D', 'G'));
indirectA.push_back(make_tuple('E', 'I'));
indirectA.push_back(make_tuple('B', 'C'));
nodeA.direct = directA;
nodeA.indirect = indirectA;


// B
Nodes nodeB;
vector<char> directB{'A', 'C', 'D', 'E', 'F', 'G', 'I'};
vector<std::tuple<char,char>> indirectB;
indirectB.push_back(make_tuple('E', 'H'));
nodeB.direct = directB;
nodeB.indirect = indirectB;


// C
Nodes nodeC;
vector<char> directC{'B', 'D', 'E', 'F', 'H'};
vector<std::tuple<char,char>> indirectC;
indirectC.push_back(make_tuple('E', 'G'));
indirectC.push_back(make_tuple('F', 'I'));
indirectC.push_back(make_tuple('B', 'A'));
nodeC.direct = directC;
nodeC.indirect = indirectC;

// D
Nodes nodeD;
vector<char> directD{'A', 'B', 'E', 'G', 'H', 'C', 'I'};
vector<std::tuple<char,char>> indirectD;
indirectD.push_back(make_tuple('E', 'F'));
nodeD.direct = directD;
nodeD.indirect = indirectD;

// E
Nodes nodeE;
vector<char> directE{'A', 'B', 'C', 'D', 'G', 'F', 'H', 'I'};
vector<std::tuple<char,char>> indirectE;
nodeE.direct = directE;
nodeE.indirect = indirectE;

// F
Nodes nodeF;
vector<char> directF{'B', 'C', 'E', 'H', 'I', 'A', 'G'};
vector<std::tuple<char,char>> indirectF;
indirectF.push_back(make_tuple('E', 'D'));
nodeF.direct = directF;
nodeF.indirect = indirectF;

// G
Nodes nodeG;
vector<char> directG{'D', 'E', 'H', 'F', 'B'};
vector<std::tuple<char,char>> indirectG;
indirectG.push_back(make_tuple('D', 'A'));
indirectG.push_back(make_tuple('E', 'C'));
indirectG.push_back(make_tuple('H', 'I'));
nodeG.direct = directG;
nodeG.indirect = indirectG;

// H
Nodes nodeH;
vector<char> directH{'D', 'E', 'F', 'G', 'I', 'A', 'C'};
vector<std::tuple<char,char>> indirectH;
indirectH.push_back(make_tuple('E', 'B'));
nodeH.direct = directH;
nodeH.indirect = indirectH;

// I
Nodes nodeI;
vector<char> directI{'B', 'D', 'E', 'F', 'H'};
vector<std::tuple<char,char>> indirectI;
indirectI.push_back(make_tuple('H', 'G'));
indirectI.push_back(make_tuple('E', 'A'));
indirectI.push_back(make_tuple('F', 'C'));
nodeI.direct = directI;
nodeI.indirect = indirectI;


graph={{'A',nodeA},{'B',nodeB},{'C',nodeC},{'D',nodeD},{'E',nodeE},{'F',nodeF},{'G',nodeG},{'H',nodeH},{'I',nodeI}};

    vector<char> test;
    //test.push_back('');
    //vector<char> res =  possibilities(test);
    //cout << countPatternsFrom('D',2) << endl;
    cout << countPatternsFrom('E',4) << endl;
    return 0;
}



//////////
// Vianney solution! is this cheating? :D smart approach Vianney!
//////////
/*
#include <array>

// based on onother solution (using const value) but here with array and constexpr
constexpr unsigned int  countPatternsFrom(char firstDot, unsigned short length) {
  if (length < 0 || length > 9){ return 0;}
  constexpr const std::array<unsigned int, 10>ACIG = {0, 1, 5, 31, 154, 684, 2516, 7104, 13792, 13792};
  constexpr const std::array<unsigned int, 10>BDFG = {0, 1, 7, 37,188,816, 2926, 8118,15564,15564};
  constexpr const std::array<unsigned int, 10>E = {0, 1, 8, 48, 256, 1152, 4248, 12024, 23280, 23280};
  constexpr const std::array<std::array<unsigned int, 10>, 10> All = {ACIG, BDFG, ACIG, BDFG, E, BDFG, ACIG, BDFG, ACIG};
  return All[firstDot-'A'][length];
}

*/



//////////
//xwtkdym solution! 
//////////
/*
int maze[3][3];
int dfs(int x, int y, int length, long long val)
{
    if (length == 0) return 1;
    int ret = 0;
    for (int i=0; i < 3; ++i)
        for (int j=0; j < 3; ++j) {
            if (maze[i][j]) continue;
            int a = abs(x+i), b = abs(y+j);
            maze[i][j] = 1;
            if (((a|b)&1) || maze[a>>1][b>>1]) {
                ret += dfs(i, j, length-1, (val+i)*10+j);
            }
            maze[i][j] = 0;
        }
    return ret;
}

unsigned int countPatternsFrom(char firstDot, unsigned short length) { 
    if (length <= 0 || length > 9) return 0;
    static int dp[5][10] = {0};
    firstDot -= 'A';
    firstDot = firstDot == 4 ? 4 : firstDot&1;
    int x = firstDot/3, y = firstDot%3;
    if (dp[firstDot][length]) 
        return dp[firstDot][length]; 
    maze[x][y] = 1;
    dp[firstDot][length] = dfs(x, y, length-1, 10 + firstDot);
    maze[x][y] = 0;
    return dp[firstDot][length]; 
}

*/