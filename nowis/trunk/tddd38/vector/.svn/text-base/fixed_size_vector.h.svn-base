#ifndef _FIXED_SIZE_VECTOR_H_
#define _FIXED_SIZE_VECTOR_H_

#include <algorithm>
#include <iterator>
#include <stdexcept>

template<typename T, int N>
struct fixed_size_vector {
public:
  typedef T                                           value_type;
  typedef value_type&                                 reference;
  typedef const reference                             const_reference;
  typedef value_type*                                 pointer;
  typedef const value_type*                           const_pointer;

  typedef int                                         size_type;
  typedef ptrdiff_t                                   difference_type;

  typedef pointer                                     iterator;
  typedef const value_type*                           const_iterator;
  typedef std::reverse_iterator<iterator>             reverse_iterator;
  typedef std::reverse_iterator<const_iterator>       const_reverse_iterator;

  T elems_[N > 0 ? N : 1];

  void fill(const T& u) {
    std::fill_n(begin(), size(), u);
  }

  void swap(fixed_size_vector<T, N>& other) {
    std::swap_ranges(begin(), end(), other.begin());
  }

  iterator       begin()       { return iterator(elems_); }
  const_iterator begin() const { return const_iterator(elems_); }
  iterator       end()         { return iterator(elems_ + N); }
  const_iterator end() const   { return const_iterator(elems_ + N); }

  reverse_iterator       rbegin()       { return reverse_iterator(end()); }
  const_reverse_iterator rbegin() const{ return const_reverse_iterator(end()); }
  reverse_iterator       rend()         { return reverse_iterator(begin()); }
  const_reverse_iterator rend() const{ return const_reverse_iterator(begin()); }

  const_iterator         cbegin()  { return const_iterator(begin()); }
  const_iterator         cend()    { return const_iterator(end()); }
  const_reverse_iterator crbegin() { return const_reverse_iterator(end()); }
  const_reverse_iterator crend()   { return const_reverse_iterator(begin()); }

  size_type size() const { return N; }
  size_type max_size() const { return N; }
  bool empty() const { return size() == 0; }

  reference       operator[](size_type pos)       { return elems_[pos]; }
  const_reference operator[](size_type pos) const { return elems_[pos]; }

  reference at(size_type n)             { check_(n); return elems_[n]; }
  const_reference at(size_type n) const { check_(n); return elems_[n]; }

  reference front()             { return *begin(); }
  const_reference front() const { return *rbegin(); }

  reference back()             { return N == 0 ? *end() : *(end() - 1); }
  const_reference back() const { return N == 0 ? *end() : *(end() - 1); }

  pointer data()             { return begin(); }
  const_pointer data() const { return rbegin(); }

private:
  inline void check_(size_type n) const {
    if(n < 0 || n >= (int) N)
      throw std::out_of_range("fixed_size_operator check");
  }
};

template <typename T, size_t N>
void
swap(fixed_size_vector<T, N>& x, fixed_size_vector<T, N>& y) {
  x.swap(y);
}

template <typename T, size_t N>
bool
operator==(const fixed_size_vector<T, N>& lhs,
           const fixed_size_vector<T, N>& rhs) {
  return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename T, size_t N>
bool
operator!=(const fixed_size_vector<T, N>& lhs,
           const fixed_size_vector<T, N>& rhs) {
  return !(lhs == rhs);
}

template <typename T, size_t N>
bool
operator<(const fixed_size_vector<T, N>& lhs,
           const fixed_size_vector<T, N>& rhs) {
  return std::lexicographical_compare(lhs.begin(), lhs.end(), 
                                      rhs.begin(), rhs.end());
}


template <typename T, size_t N>
bool
operator>(const fixed_size_vector<T, N>& lhs,
          const fixed_size_vector<T, N>& rhs) {
  return rhs < lhs; 
}

template <typename T, size_t N>
bool
operator<=(const fixed_size_vector<T, N>& lhs,
           const fixed_size_vector<T, N>& rhs) {
  return !(lhs > rhs);
}

template <typename T, size_t N>
bool
operator>=(const fixed_size_vector<T, N>& lhs,
           const fixed_size_vector<T, N>& rhs) {
  return !(lhs < rhs);
}

#endif

