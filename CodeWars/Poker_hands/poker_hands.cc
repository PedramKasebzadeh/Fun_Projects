#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;


struct PokerHand {
  string hand;
};

bool is_flush(PokerHand hand){
    if((hand[1]==hand[4])&&(hand[7]==hand[10])&&(hand[13]==hand[1])&&(hand[7]==hand[4])){
        return true;
    } else{
    return false;
    }   }


int picture_cards(char card){
    if( card == 'T' ) return 10;
    if( card == 'J' ) return 11;
    if( card == 'Q' ) return 12;
    if( card == 'K' ) return 13;
    if( card == 'A' ) return 14;
    int j = card - '0';
    return j;
}




bool is_FourOfAKind(string hand){
    int num[5]={0,3,6,9,12};
    vector<int> vec;
    string str;
    for (int i:num){
        vec.push_back(picture_cards(hand[i]));
    }
    int check=0;
    sort(vec.begin(),vec.end());
    for(int i=0;i<5;i++){
        if(vec[i]==vec[i+1])
            check++;
    }
    return (check>=3?true:false);
}

bool is_ThreeOfAKind(string hand){
    int num[5]={0,3,6,9,12};
    vector<int> vec;
    string str;
    for (int i:num){
        vec.push_back(picture_cards(hand[i]));
    }
    int check=0;
    sort(vec.begin(),vec.end());
    for(int i=0;i<5;i++){
        if(vec[i]==vec[i+1])
            check++;
    }
    return (check>=2?true:false);
}


bool is_FullHouse(string hand){
    int num[5]={0,3,6,9,12};
    vector<int> vec;
    string str;
    for (int i:num){
        vec.push_back(picture_cards(hand[i]));
    }
    map<int,int> full;
    int value;
    for(int card:vec){
        value = full[card];
        full[card]++;
    }
    if(full.size()==2){
        for(std::map<int,int>::iterator it = full.begin(); it != full.end(); ++it) {
            if(it->second==2 || it->second==3){return true;}
    }
    }
    return false;
}


bool is_TwoPairs(string hand){
    int num[5]={0,3,6,9,12};
    vector<int> vec;
    string str;
    for (int i:num){
        vec.push_back(picture_cards(hand[i]));
    }
    map<int,int> full;
    int value;
    for(int card:vec){
        value = full[card];
        full[card]++;
    }
    if(full.size()==3){
        for(std::map<int,int>::iterator it = full.begin(); it != full.end(); ++it) {
            if(it->second==2 || it->second==1){return true;}
    }
    }
    return false;
}


bool is_Pairs(string hand){
    int num[5]={0,3,6,9,12};
    vector<int> vec;
    string str;
    for (int i:num){
        vec.push_back(picture_cards(hand[i]));
    }
    map<int,int> full;
    int value;
    for(int card:vec){
        value = full[card];
        full[card]++;
    }
    if(full.size()==4){
        return true;
    }
    return false;
}




bool is_straight(string hand){
    int num[5]={0,3,6,9,12};
    vector<int> vec;
    string str;
    for (int i:num){
        vec.push_back(picture_cards(hand[i]));
    }
    bool res;
    sort(vec.begin(),vec.end());
    for(int i=0;i<4;i++){
        if(vec[i]+1 != vec[i+1]){
            return false;
        } 
    }
    return true;
  }


bool is_stright_flush(string hand){
    if(is_straight(hand)&&is_flush(hand)){
        return true;
    } else{
    return false;
    }   }

int highest(PokerHand &hand){
    int num[5]={0,3,6,9,12};
    vector<int> vec;
    string str;
    for (int i:num){
        vec.push_back(picture_cards(hand[i]));
    }
    int max = *max_element(vec.begin(), vec.end());
    return max; 
     }


bool is_royal_flush(string hand){
    if(!is_stright_flush(hand)){
        return false;
    }
    int num[5]={0,3,6,9,12};
    vector<int> vec;
    string str;
    for (int i:num){
        vec.push_back(picture_cards(hand[i]));
        }
    if(std::find(vec.begin(), vec.end(), 14) != vec.end()) {
        return true;
    }
    return false;
}

int hand_rate(string hand){
    int res = highest(hand);
    if (is_royal_flush(hand)){return res+150;}
    if (is_stright_flush(hand)){return res+130;}
    if (is_FourOfAKind(hand)){return res+110;}
    if (is_FullHouse(hand)){return res+88;}
    if (is_flush(hand)){return res+74;}
    if (is_straight(hand)){return res+59;}
    if (is_ThreeOfAKind(hand)){return res+44;}
    if (is_TwoPairs(hand)){return res+29;}
    if (is_Pairs(hand)){return res+14;}
    return res;
}

enum class Result { Win, Loss, Tie };

Result compare (PokerHand player, PokerHand opponent) {
  if ( hand_rate(player) > hand_rate(opponent) ){return Result::Win;}
  if ( hand_rate(player) < hand_rate(opponent) ){return Result::Loss;}
  if ( hand_rate(player) = hand_rate(opponent) ){return Result::Tie;}
}

/* cool approach by Jerzy0rzl0wski

#include <cassert>
#include <array>
#include <algorithm>
#include <iostream>

enum class Result
{
  Win,
  Loss,
  Tie
};

enum class HandCategories
{
  StraightFlush = 0,
  FourOfKind,
  FullHouse,
  Flush,
  Straight,
  ThreeOfKind,
  TwoPairs,
  Pair,
  Highcard
};

struct PokerHand
{
private:
  std::array<int, 5> card;
  std::array<int, 15> kind_count = {};
  std::array<int, 15> kind_count_sort;
  std::array<int, 5> card_sorted_by_group;
  int most_numerous_kind;
  int second_numerous_kind;
  bool flush = true;
  bool straight = true;
  HandCategories category;
  HandCategories setCategory();

public:
  PokerHand(const char *pokerhand);
  HandCategories getCategory() const;
  std::array<int, 5> getCard_sorted_by_group() const;
};

PokerHand::PokerHand(const char *pokerhand)
{

  for (int i = 0; i < 5; i++)
  {
    switch (pokerhand[i * 3])
    {
    case 'T':
      card[i] = 10;
      break;
    case 'J':
      card[i] = 11;
      break;
    case 'Q':
      card[i] = 12;
      break;
    case 'K':
      card[i] = 13;
      break;
    case 'A':
      card[i] = 14;
      break;
    default:
      card[i] = pokerhand[i * 3] - 48;
      break;
    }
    kind_count[card[i]]++;
    if (pokerhand[1] != pokerhand[i * 3 + 1])
    {
      flush = false;
    }
  }

  //check straight
  std::sort(card.begin(), card.end(), std::greater<int>());
  for (int i = 0; i < 4; i++)
  {
    if ((card[i]) != (card[i + 1] + 1))
    {
      straight = false;
      break;
    }
  }
  //Low-ace straight
  if (card[0] == 14 && card[1] == 5 && card[2] == 4 && card[3] == 3 && card[4] == 2)
  {
    straight = true;
    card[0] = 1;
    std::sort(card.begin(), card.end(), std::greater<int>());
  }

  //sort by kind
  for (int i = 0; i < 5; i++)
  {
    card_sorted_by_group[i] = card[i] + kind_count[card[i]] * 100;
  }

  std::sort(card_sorted_by_group.begin(), card_sorted_by_group.end(), std::greater<int>());

  for (int i = 0; i < 5; i++)
  {
    card_sorted_by_group[i] = card_sorted_by_group[i] % 100;
  }

  kind_count_sort = kind_count;
  std::sort(kind_count_sort.begin(), kind_count_sort.end(), std::greater<int>());
  most_numerous_kind = kind_count_sort[0];
  second_numerous_kind = kind_count_sort[1];

  //set category
  category = setCategory();
}

HandCategories PokerHand::setCategory()
{
  if (most_numerous_kind == 2)
  {
    if (second_numerous_kind == 2)
    {
      return HandCategories::TwoPairs;
    }
    else
    {
      return HandCategories::Pair;
    }
  }

  if (most_numerous_kind == 3)
  {
    if (second_numerous_kind == 2)
    {
      return HandCategories::FullHouse;
    }
    else
    {
      return HandCategories::ThreeOfKind;
    }
  }

  if (most_numerous_kind == 4)
  {
    return HandCategories::FourOfKind;
  }

  if ((straight == true) && (flush == true))
  {
    return HandCategories::StraightFlush;
  }

  if (straight == true)
  {
    return HandCategories::Straight;
  }

  if (flush == true)
  {
    return HandCategories::Flush;
  }

  return HandCategories::Highcard;
}

HandCategories PokerHand::getCategory() const
{
  return category;
}

std::array<int, 5> PokerHand::getCard_sorted_by_group() const
{
  return card_sorted_by_group;
}

Result compare(const PokerHand &player, const PokerHand &opponent)
{
  if ((static_cast<int>(player.getCategory())) < (static_cast<int>(opponent.getCategory())))
  {
    return Result::Win;
  }

  if ((static_cast<int>(player.getCategory())) > (static_cast<int>(opponent.getCategory())))
  {
    return Result::Loss;
  }

  for (int i = 0; i < 5; i++)
  {
    if (player.getCard_sorted_by_group()[i] > opponent.getCard_sorted_by_group()[i])
    {
      return Result::Win;
    }

    if (player.getCard_sorted_by_group()[i] < opponent.getCard_sorted_by_group()[i])
    {
      return Result::Loss;
    }
  }

  return Result::Tie;
}

bool run_test_hands(const PokerHand &player, const PokerHand &opponent, Result outcome)
{
  return outcome == compare(player, opponent);
}

bool run_test(const char *player, const char *opponent, Result outcome)
{
  return run_test_hands(PokerHand(player), PokerHand(opponent), outcome);
}

bool check_category(const char *player, HandCategories outcome)
{
  return outcome == PokerHand(player).getCategory();
}

int main()
{
  assert(check_category("2H 3H 4H 5H 6H", HandCategories::StraightFlush));
  assert(check_category("JS JD AD JC JH", HandCategories::FourOfKind));
  assert(check_category("2S AH 2H AS AC", HandCategories::FullHouse));
  assert(check_category("2H 3H 5H 6H 7H", HandCategories::Flush));
  assert(check_category("2S 3H 4H 5S 6C", HandCategories::Straight));
  assert(check_category("AH AC 5H 6H AS", HandCategories::ThreeOfKind));
  assert(check_category("2H 6H 4H 2H 6H", HandCategories::TwoPairs));
  assert(check_category("2H 5H 4D 2H 6H", HandCategories::Pair));
  assert(check_category("2H 8D 4H 5H 6H", HandCategories::Highcard));

  assert(run_test("2H 3H 4H 5H 6H", "AS AD AC AH JD", Result::Win));  // "Straight flush wins of 4 of a kind"
  assert(run_test("2S AH 2H AS AC", "JS JD JC JH AD", Result::Loss)); // "4 Of a kind wins of full house"
  assert(run_test("2S AH 2H AS AC", "2H 3H 5H 6H 7H", Result::Win));  // "Full house wins of flush"
  assert(run_test("2H 3H 5H 6H 7H", "2S 3H 4H 5S 6C", Result::Win));  // "Flush wins of straight"
  assert(run_test("2S 3H 4H 5S 6C", "3D 4C 5H 6H 2S", Result::Tie));  // "Equal straight is tie"
  assert(run_test("2S 3H 4H 5S 6C", "AH AC 5H 6H AS", Result::Win));  // "Straight wins of three of a kind"
  assert(run_test("2S 3H 4H 5S AC", "AH AC 5H 6H AS", Result::Win));  // "Low-ace straight wins of three of a kind"
  assert(run_test("2S 2H 4H 5S 4C", "AH AC 5H 6H AS", Result::Loss)); // "3 Of a kind wins of two pair"
  assert(run_test("2S 2H 4H 5S 4C", "AH AC 5H 6H 7S", Result::Win));  // "2 Pair wins of pair"
  assert(run_test("2S AH 4H 5S 6C", "AD 4C 5H 6H 2C", Result::Tie));  // "Equal cards is tie"
  assert(run_test("2S AH 4H 5S KC", "AH AC 5H 6H 7S", Result::Loss)); // "Pair wins of nothing"
  assert(run_test("6S AD 7H 4S AS", "AH AC 5H 6H 7S", Result::Loss)); // "Highest pair wins"
  assert(run_test("2S 3H 6H 7S 9C", "7H 3C TH 6H 9S", Result::Loss)); // "Highest card loses"
  assert(run_test("4S 5H 6H TS AC", "3S 5H 6H TS AC", Result::Win));  // "Highest card wins"
  assert(run_test("2H 3H 4H 5H 6H", "KS AS TS QS JS", Result::Loss)); // "Highest straight flush wins"
  assert(run_test("AS AH 2H AD AC", "JS JD JC JH 3D", Result::Win));  // "Highest 4 of a kind wins"
  assert(run_test("AS 3S 4S 8S 2S", "2H 3H 5H 6H 7H", Result::Win));  // "Highest flush wins"
  std::cout << "Passed!" << std::endl;
}

*/