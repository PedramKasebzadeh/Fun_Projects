#include <stdexcept>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Date {
public:
  virtual ~Date() {}
  virtual void print(ostream& os) const = 0;
protected:
  Date() {}
private:
  Date(Date& other);
  Date& operator=(Date& other);
};

ostream& operator<<(ostream& os, const Date& d) {
  d.print(os);
  return os;
}

class Int_Date : public Date {
public:
  Int_Date(int y, int m, int d) throw (invalid_argument) : year_(y), month_(m),
                                                           day_(d) {
    if(month_ < 1 || month_ > 12 || day_ < 1 || day_ > 31)
      throw invalid_argument("BAaaAADD");
  }

  void print(ostream& os) const {
    os << year_ << "-" << month_ << "-" << day_;
  }
private:
  int year_;
  int month_;
  int day_;
};

class Cstring_date : public Date {
public:
  ~Cstring_date() {
    delete[] year_;
    delete[] month_;
    delete[] day_;
  }

  Cstring_date(char *y, char *m, char *d) {
    year_ = strcpy(new char[strlen(y)+1], y);
    try {
      month_ = strcpy(new char[strlen(m)+1], m);
    }catch(...) {
      delete[] year_;
      throw;
    }

    try {
      day_ = strcpy(new char[strlen(d)+1], d);
    }catch(...) {
      delete[] year_;
      delete[] day_;
      throw;
    }
  }

  void print(ostream& os) const {
    os << month_ << " " << day_ << ", " << year_;
  }

private:
  char *year_;
  char *month_;
  char *day_;
};

int main() {
  vector<Date *> dates;

  dates.push_back(new Int_Date(2009, 1, 25));
  dates.push_back(new Int_Date(42, 4, 2));
  dates.push_back(new Cstring_date("Mouhaha", "haha", "ha"));
  dates.push_back(new Int_Date(42, 1, 25));
  dates.push_back(new Cstring_date("1988", "January", "20"));

  for(vector<Date *>::iterator it = dates.begin() ; it != dates.end() ; it++)
    cout << **it << endl;

  return 0;
}

