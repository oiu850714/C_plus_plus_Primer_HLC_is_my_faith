// This solution refers to
// https://github.com/Mooophy/Cpp-Primer/blob/master/ch16/ex16.28/unique_pointer.h
#ifndef _UNIQUEPTR_H_
#define _UNIQUEPTR_H_

#include "Deleter.h"
#include <vector>

template <typename, typename> class UniquePtr;
template <typename T, typename D>
void swap(UniquePtr<T, D> &lhs, UniquePtr<T, D> &rhs);

template <typename T, typename D = Deleter> class UniquePtr {

public:
  // preventing copy and assignment
  UniquePtr(const UniquePtr &) = delete;
  UniquePtr &operator=(const UniquePtr &) = delete;

  // default constructor and one taking T*
  UniquePtr() = default;
  explicit UniquePtr(T *raw_ptr) : ptr(raw_ptr) {}

  // move constructor
  UniquePtr(UniquePtr &&up) noexcept : ptr(up.ptr) { up.ptr = nullptr; }

  // move assignment
  UniquePtr &operator=(UniquePtr &&rhs) noexcept;

  // std::nullptr_t assignment, can assign nullptr to UniquePtr
  UniquePtr &operator=(std::nullptr_t n) noexcept;

  // operator overloaded :  *  ->  bool
  T &operator*() const { return *ptr; }
  T *operator->() const { return &operator*(); }
  operator bool() const { return ptr; }

  // return the underlying pointer
  T *get() const noexcept { return ptr; }

  // swap member using swap friend
  void swap(UniquePtr<T, D> &rhs) { ::swap(*this, rhs); }

  // free and make it point to nullptr or to p's pointee.
  void reset() noexcept {
    deleter(ptr);
    ptr = nullptr;
  }
  void reset(T *p) noexcept {
    deleter(ptr);
    ptr = p;
  }

  // return ptr and make ptr point to nullptr.
  T *release();

  ~UniquePtr() { deleter(ptr); }

private:
  T *ptr = nullptr;
  D deleter = D();
};

// swap
template <typename T, typename D>
inline void swap(UniquePtr<T, D> &lhs, UniquePtr<T, D> &rhs) {
  using std::swap;
  swap(lhs.ptr, rhs.ptr);
  swap(lhs.deleter, rhs.deleter);
}

// move assignment
template <typename T, typename D>
inline UniquePtr<T, D> &UniquePtr<T, D>::operator=(UniquePtr &&rhs) noexcept {
  // prevent self-assignment
  if (this->ptr != rhs.ptr) {
    deleter(ptr);
    ptr = nullptr;
    ::swap(*this, rhs);
  }
  return *this;
}

// std::nullptr_t assignment
template <typename T, typename D>
inline UniquePtr<T, D> &UniquePtr<T, D>::operator=(std::nullptr_t n) noexcept {
  if (n == nullptr) {
    deleter(ptr);
    ptr = nullptr;
  }
  return *this;
}

// relinquish control by returnning ptr and making ptr point to nullptr.
template <typename T, typename D> inline T *UniquePtr<T, D>::release() {
  T *ret = ptr;
  ptr = nullptr;
  return ret;
}

#endif