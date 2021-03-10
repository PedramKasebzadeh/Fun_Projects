/*
 * smart_pointer.h     Smart pointer I, Given code.
 */
#ifndef _SMARTPOINTER_I_H
#define _SMARTPOINTER_I_H

namespace IDA_Smart_Pointer_I
{
  class smart_pointer
  {
  public:
    explicit smart_pointer(int* p = 0) : ptr_(p) {}

    smart_pointer(const smart_pointer& rhs);

    ~smart_pointer();

    smart_pointer& operator=(const smart_pointer& rhs);

    smart_pointer& operator=(int *rhs);

    int& operator*();
    int operator*() const;

    int* operator->();
    const int* operator->() const;

    bool operator!();

    bool operator==(const smart_pointer& rhs);
    friend bool operator==(const smart_pointer& lhs, const int *rhs);

    bool operator!=(const smart_pointer& rhs);
    friend bool operator!=(const smart_pointer& lhs, const int *rhs);

    void swap(smart_pointer& other);
  private:
    int* ptr_;

    void copy(const smart_pointer& p);
  };

  bool operator==(const smart_pointer& lhs, const int *rhs);
  bool operator!=(const smart_pointer& lhs, const int *rhs);
} // namespace IDA_Smart_Pointer_I

#endif

