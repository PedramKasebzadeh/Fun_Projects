#include <algorithm>

namespace IDA_Smart_Pointer_II
{
  template <typename T>
  smart_pointer<T>::smart_pointer(const smart_pointer<T>& other) {
    copy(other);
  }

  template <typename T>
  smart_pointer<T>::~smart_pointer() {
    if(ptr_)
      delete ptr_;
  }

  template <typename T>
  T& smart_pointer<T>::operator*() {
    return *ptr_;
  }

  template <typename T>
  const T& smart_pointer<T>::operator*() const {
    return *ptr_;
  }

  template <typename T>
  T* smart_pointer<T>::operator->() {
    return ptr_;
  }

  template <typename T>
  const T* smart_pointer<T>::operator->() const {
    return ptr_;
  }

  template <typename T>
  void smart_pointer<T>::swap(smart_pointer<T>& other) {
    std::swap(ptr_, other.ptr_);
  }

  template <typename T>
  void smart_pointer<T>::copy(const smart_pointer<T>& p) {
    ptr_ = p.ptr_ ? new T(*(p.ptr_)) : 0;
  }
         
  template <typename T>
  bool smart_pointer<T>::operator!() const {
    return ptr_ == 0;
  }
} // namespace IDA_Smart_Pointer_II

