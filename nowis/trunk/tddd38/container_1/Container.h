#ifndef _CONTAINER_H_
#define _CONTAINER_H_
#include <cstdlib>

template <typename T>
class Container
{
   public:
      explicit Container(const std::size_t n = 0);
      Container(const Container<T>& other);
      ~Container();

      Container<T>& operator=(const Container<T>& rhs);

      int size() const { return size_; };
      size_t capacity() const { return capacity_; };
      bool empty() const { return size_ == 0; };

      void swap(Container<T>& other);

      void push_back(const T& o);
      void pop_back();
      T& back();
      const T& back() const;

   private:
      T*          elems_;
      std::size_t capacity_;
      std::size_t size_;

      T* copy(const Container<T>& other, const std::size_t newCapacity);
};

template <typename T>
void swap(Container<T>& a, Container<T>& b) {
  a.swap(b);
}

#include "Container.tcc"

#endif
