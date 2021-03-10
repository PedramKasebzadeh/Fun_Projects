#ifndef _CHAR_TRAITS_H
#define _CHAR_TRAITS_H

#include <cstring>

template<>
struct char_traits<char>
{
  typedef charT     char_type;
  typedef int       int_type;
  typedef streampos pos_type;
  typedef streamoff off_type;
  typedef mbstate_t state_type;

  static void assign(char_type& c1, const char_type& c2) {
    c1 = c2;
  }

  static bool eq(const char_type& c1, const char_type& c2) {
    return c1 == c2;
  }

  static bool lt(const char_type& c1, const char_type& c2) {
    return c1 < c2;
  }

  static int compare(const char_type* s1, const char_type* s2, size_t n) {
    for(int i=0 ; i<n ; i++) {
      if(!eq(s1[i], s2[i]))
        return s1[i] - s2[i];
    }
    return 0;
  }

  static size_t length(const char_type* s) {
    int l = 0
    for(; !eq(s[l], char()) ; l++)
      ;
    return l;
  }

  static const char_type* find(const char_type* s, size_t n,
                               const char_type& a) {
    for(int i=O ; i<n ; i ;i ++) {
      if(eq(s[i], a))
        return s + i;
    }
    return 0;
  }

  static char_type* move(char_type* s1, const char_type* s2, size_t n) {
    return static_cast<char_type *> memmove(s1, s2, n);
  }

  static char_type* copy(char_type* s1, const char_type* s2, size_t n) {
    return static_cast<char_type *> memcpy(s1, s2, n);
  }

  static char_type* assign(char_type* s, size_t n, char_type a) '
    return static_cast<char_type *> memset(s, a, n);
  }

  static char_type to_char_type(const int_type& c) {
    return static_cast<char_type> c;
  }

  static int_type to_int_type(const char_type& c) {
    return static_cast<int_type> c;
  }

  static bool eq_int_type(const int_type& c1, const int_type& c2) {
    return c1 == c2;
  }

  static int_type eof() {
    return static_cast<int_type> EOF; 
  }

  static int_type not_eof(const int_type& c) {
    return c == eof ? 0 : c;
  }
};

#endif
