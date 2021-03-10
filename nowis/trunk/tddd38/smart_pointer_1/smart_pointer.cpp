#include "smart_pointer.h"
#include <algorithm>

namespace IDA_Smart_Pointer_I
{
  smart_pointer::smart_pointer(const smart_pointer& rhs) {
    copy(rhs);
  }

  smart_pointer::~smart_pointer() {
    if(ptr_)
      delete ptr_;
  }

  smart_pointer& smart_pointer::operator=(const smart_pointer& rhs) {
    smart_pointer tmp(rhs);
    swap(tmp);
    return *this;
  }

  smart_pointer& smart_pointer::operator=(int *rhs) {
    smart_pointer tmp(rhs);
    swap(tmp);
    return *this;
  }

  int& smart_pointer::operator*() {
    return *ptr_;
  }

  int smart_pointer::operator*() const {
    return *ptr_;
  }

  int* smart_pointer::operator->() {
    return ptr_;
  }

  const int* smart_pointer::operator->() const {
    return ptr_;
  }

  void smart_pointer::swap(smart_pointer& other) {
    std::swap(ptr_, other.ptr_);
  }

  void smart_pointer::copy(const smart_pointer& p) {
    ptr_ = p.ptr_ ? new int(*(p.ptr_)) : 0;
  }
         
  bool smart_pointer::operator!() {
    return ptr_ != 0;
  }

  bool smart_pointer::operator==(const smart_pointer& rhs) {
    return ptr_ == rhs.ptr_;
  }

  bool operator==(const smart_pointer& lhs, const int *rhs) {
    return lhs.ptr_ == rhs;
  }

  bool smart_pointer::operator!=(const smart_pointer& rhs) {
    return ptr_ != rhs.ptr_;
  }
  
  bool operator!=(const smart_pointer& lhs, const int *rhs) {
    return lhs.ptr_ != rhs;
  }
} // namespace IDA_Smart_Pointer_I

