#include "Time.h"
#include <iostream>
#include <string>
#include<sstream>
#include <ostream>
#include <iomanip>
#include <string> 
#include <stdexcept>


// Checking for validity of the input
bool is_valid(Time const& t) 
{
    bool valid_hrs{0 <= t.hours and t.hours < 24}; // The hour should be in [0:23] interval
    bool valid_min{0 <= t.minutes and t.minutes < 60};// The minute should be in [0:59] interval
    bool valid_sec{0 <= t.seconds and t.seconds < 60};// The second should be in [0:59] interval

    return valid_hrs and valid_min and valid_sec;
}

// Transform time to string 
std::string to_string(Time t,int format=24)
{
  is_valid(t);
  std::string p;
  std::string hour_string;
  if(format==12)
  {
    if (t.hours>11)
    {
    t.hours -= 12; 
    p= "[pm]";
    } else {p = "[am]";}
  }
  if (t.hours<10){hour_string += "0";}
  hour_string +=std::to_string(t.hours);
  hour_string += ":";
  if(t.minutes <= 9){hour_string += "0";}
  hour_string += std::to_string(t.minutes);
  hour_string+=":";
  if(t.seconds <= 9){hour_string += "0";}
  hour_string += std::to_string(t.seconds);
  if(format==12)
  {
    hour_string+=" ";
    hour_string +=p;
  }
  if(format != 24 & format != 12){
     throw std::invalid_argument( "Error: your input format doesn't make any sense! use either \"12\" or \"24\"." );
  }
  return hour_string;
}

// Is it morning already?
bool is_am(Time t){
  return(t.hours<12);
}


// "+" operator implimentation
Time& operator+(Time & t, int N){
  t.seconds = t.seconds + N;
  if(t.seconds>59)
  {
      t.minutes += floor(t.seconds/60);
      t.seconds = t.seconds%60;
      if(t.minutes>59)
      {
          t.hours+=floor(t.minutes/60);;
          t.minutes = t.minutes%60;
          if(t.hours>23)
          {
              t.hours = t.hours%24;
          }
      }   
  }
  while(t.seconds < 0){
      t.seconds += 60;
      t.minutes -= 1;
      while(t.minutes < 0){
        t.minutes += 60;
        t.hours -= 1;
        if(t.hours < 0){
          t.hours += 24;
        }
      }
    }
  return t;
}

// "-" operator implimentation
Time& operator -(Time& t, int secs){
  t = t + (-secs);
  return t;
}



// "i++" operator implimentation
Time& operator++(Time & t){
  t+1;
  return t;
}

//// "++i" operator implimentation
Time operator++(Time & t, int N){
  Time temp{t};
   temp+1;
  return temp;
}


// "--" operator implimentation
Time& operator --(Time & t){
  t-1;
  return t;
}
Time operator --(Time & t, int N){
  Time  temp{t};
   temp-1;
  return temp;
}



// ">" operator implimentation
bool operator >(Time const& t1, Time const& t2){
    if(t1.hours==t2.hours && t1.minutes==t2.minutes){
      return t1.seconds>t2.seconds;
    } else if(t1.hours==t2.hours){
      return t1.minutes >t2.minutes;
    } else{
      return t1.hours>t2.hours;
    }
}


// "<" operator implimentation
bool operator <(Time const& t1, Time const& t2){
    return t2 > t1;
}

// "==" operator implimentation
bool operator ==(Time const& t1, Time const& t2){
    if(t1>t2 || t1<t2){
      return false; 
    }else{
      return true;
    };
}

// "<=" operator implimentation
bool operator <=(Time const& t1, Time const& t2){
    return (t1 < t2) or (t2==t1) ;
}


// ">=" operator implimentation
bool operator >=(Time const& t1, Time const& t2){
    return (t1 > t2) or (t1==t2) ;
}

// "!=" operator implimentation
bool operator !=(Time const& t1, Time const& t2){
    if(t1==t2){
      return false;
    } else {
      return true;
    }
}



// "<<" operator implimentation
std::ostream& operator <<(std::ostream& os, Time const& t){
  os << to_string(t,24);
    return os;
}


// ">>" operator implimentation
std::istream& operator >>(std::istream& is, Time & t){
  char trash{};
  Time temp{0,0,0};
  is>>temp.hours;
  is>>trash>>temp.minutes;
  is>>trash>>temp.seconds;
  if(!is_valid(temp)){
    is.setstate(std::ios_base::failbit);
    return is;
  }
  t=temp;
  return is;
}


