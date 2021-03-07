#ifndef TIME_H
#define TIME_H
#include <string>

struct Time{
  int hours{0};
  int minutes{0};
  int seconds{0};
};
bool is_valid(Time const& t); 
std::string to_string(Time t,int format); 
bool is_am(Time t);
Time& operator +(Time & t, int N);
Time& operator -(Time & t, int N);
Time& operator++(Time & t);
Time operator++(Time & t, int N);
Time& operator--(Time & t);
Time operator--(Time & t, int N);
bool operator >(Time const& t1, Time const& t2);
bool operator <(Time const& t1, Time const& t2);
bool operator ==(Time const& t1, Time const& t2);
bool operator <=(Time const& t1, Time const& t2);
bool operator >=(Time const& t1, Time const& t2);
bool operator !=(Time const& t1, Time const& t2);
std::ostream& operator <<(std::ostream& os, Time const& t);
std::istream& operator >>(std::istream& is, Time & t);
#endif