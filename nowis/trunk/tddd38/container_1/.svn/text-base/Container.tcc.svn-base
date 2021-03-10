#include <string>

template <typename T>
Container<T>::
Container(const std::size_t n) : elems_(0), capacity_(n), size_(0) {
  if(capacity_ > 0)
    elems_ = new T[capacity_]; 
}

template <typename T>
Container<T>::
Container(const Container<T>& other)
  : elems_(copy(other, other.capacity_)), capacity_(other.capacity_),
    size_(other.size_) {
}

template <typename T>
Container<T>::
~Container() {
  if(elems_)
    delete[] elems_;
}

template <typename T>
Container<T>& Container<T>::
operator=(const Container<T>& rhs) {
  if(this != &rhs) {
    T* newElems = copy(rhs, rhs.capacity_); 

    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
    delete[] elems_;
    elems_ = newElems; 
  }

  return *this;
}

template <typename T>
T* Container<T>::
copy(const Container<T>& other, const std::size_t newCapacity) {
  T* p = new T[newCapacity];
  
  try {
    std::copy(other.elems_, other.elems_ + other.size_, p);
  } catch(...) {
    delete[] p;
    throw;
  }
  
  return p;
}

template <typename T>
void Container<T>::
swap(Container<T>& other) {
  std::swap(elems_, other.elems_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <typename T>
void Container<T>::
push_back(const T& o) {
  if(size_ < capacity_) {
    elems_[size_++] = o;
  } else {
    size_t newCapa = (capacity_ == 0) ? 1 : 2*capacity_;
    T* newElems = copy(*this, newCapa);
  
    try {
      newElems[size_] = o;
    } catch (...) {
      delete[] newElems;
      throw;
    }
  
    size_++;
    delete[] elems_;
    elems_ = newElems;
    capacity_ = newCapa;
  }
}

template <typename T>
void Container<T>::
pop_back() {
  if(size_ == 0)
    throw std::string("pop_back: no element"); 
  size_--;
}

template <typename T>
T& Container<T>::
back() {
  if(size_ == 0)
    throw std::string("back: no element");
  return elems_[size_ - 1];
}

template <typename T>
const T& Container<T>::
back() const {
  if(size_ == 0)
    throw std::string("back: no element");
  return elems_[size_ - 1];
}

