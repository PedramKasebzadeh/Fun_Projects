#ifndef _CI_CHAR_TRAITS_H
#define _CI_CHAR_TRAITS_H

#include <string>
#include <cstring>

struct ci_char_traits : public std::char_traits<char>
{
  static bool eq(const char_type& c1, const char_type& c2) {
    return tolower(c1) == tolower(c2);
  }

  static bool lt(const char_type& c1, const char_type& c2) {
    return tolower(c1) < tolower(c2);
  }

  static int compare(const char_type* s1, const char_type* s2, size_t n) {
    return strncasecmp(s1, s2, n);
  }

  static const char_type* find(const char_type* s, size_t n,
                               const char_type& a) {
    for(int i=0 ; i<n ; i++) {
      if(eq(s[i], a))
        return s + i;
    }
    return 0;
  }
};

#endif
