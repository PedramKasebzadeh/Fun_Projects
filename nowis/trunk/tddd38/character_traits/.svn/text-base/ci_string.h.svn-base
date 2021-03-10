#ifndef _CI_STRING_H_
#define _CI_STRING_H_

#include <iostream>
#include <iomanip>
#include "ci_char_traits.h"

typedef std::basic_string<char, ci_char_traits> ci_string;

std::ostream& operator<<(std::ostream& o, const ci_string& s) {
  return (o << s.c_str());
}

std::istream& operator>>(std::istream& i, ci_string& s) {
  char buf[256];
  i >> std::setw(255) >> buf;
  s = buf;
  return i;
}

#endif
