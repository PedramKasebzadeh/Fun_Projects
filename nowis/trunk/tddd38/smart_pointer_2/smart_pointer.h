/*
 * smart_pointer.h     Smart pointer I, Given code.
 */
#ifndef _SMARTPOINTER_I_H
#define _SMARTPOINTER_I_H

namespace IDA_Smart_Pointer_II
{
  template <typename T>
  class smart_pointer
  {
  public:
    explicit smart_pointer(T *p = 0) : ptr_(p) {}

    smart_pointer(const smart_pointer<T>& other);

    ~smart_pointer();

    smart_pointer<T>& operator=(const smart_pointer<T>& rhs) {
      smart_pointer<T> tmp(rhs);
      swap(tmp);
      return *this;
    }
    
    smart_pointer<T>& operator=(const T *rhs) {
      smart_pointer<T> tmp(const_cast<T*>(rhs));
      swap(tmp);
      return *this;
    }
    
	  // Type conversion from smart_pointer<T> to smart_pointer<const T>.
	  // Allows assignment smart_pointer<const T> = smart_pointer<T>.
    operator smart_pointer<const T>() const
    {
      return smart_pointer<const T>(new T(*ptr_));
    }

    T& operator*();
    const T& operator*() const;

    T* operator->();
    const T* operator->() const;

    bool operator!() const;

    // for sp<T> == sp<U> and sp<U> == sp<T> (to access private member ptr_)
    template<typename U> friend class smart_pointer;
    
    // sp<T> == sp<U>
    template <typename U>
    bool operator==(const smart_pointer<U>& rhs) const {
      return ptr_ == rhs.ptr_;
    }
  
    // sp<T> = T*
    friend bool operator==(const smart_pointer<T>& lhs, const T *rhs) {
      return lhs.ptr_ == rhs;
    }

    // sp<T> == U*
    template <typename U>
    friend bool operator==(const smart_pointer<T>& lhs, const U *rhs) {
      return lhs.ptr_ == rhs;
    }
    
    // T* == sp<T>
    friend bool operator==(const T *lhs, const smart_pointer<T>& rhs) {
      return lhs == rhs.ptr_;
    }

    // U* == sp<T>
    template <typename U>
    friend bool operator==(const U *lhs, const smart_pointer<T>& rhs) {
      return lhs == rhs.ptr_;
    }

    // sp<T> != sp<U>
    template <typename U>
    bool operator!=(const smart_pointer<U>& rhs) const {
      return ptr_ != rhs.ptr_;
    }
   
    // sp<T> != T*
    friend bool operator!=(const smart_pointer<T>& lhs, const T *rhs) {
      return lhs.ptr_ != rhs;
    }

    // sp<T> != U*
    template <typename U>
    friend bool operator!=(const smart_pointer<T>& lhs, const U *rhs) {
      return lhs.ptr_ != rhs;
    }
    
    // T* != sp<T*>
    friend bool operator!=(const T *lhs, const smart_pointer<T>& rhs) {
      return lhs != rhs.ptr_;
    }

    // U* != sp<T>
    template <typename U>
    friend bool operator!=(const U *lhs, const smart_pointer<T>& rhs) {
      return lhs != rhs.ptr_;
    }

    void swap(smart_pointer<T>& other);
  private:
    T* ptr_;

    void copy(const smart_pointer<T>& p);
  };

} // namespace IDA_Smart_Pointer_II

#include "smart_pointer.tcc"

#endif

