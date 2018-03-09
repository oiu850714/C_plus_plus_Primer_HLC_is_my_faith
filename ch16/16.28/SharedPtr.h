// This solution refers to
// https://github.com/Mooophy/Cpp-Primer/blob/master/ch16/ex16.28/shared_pointer.hpp

#ifndef _SHAREDPTR_H_
#define _SHAREDPTR_H_

#include "Deleter.h"
#include <functional>

template <typename T> class SharedPtr {
public:
  //   (constructor)
  //   (destructor)
  //   operator=
  //   swap
  //   reset
  //   get
  //   operator*
  //   operator->
  //   use_count
  //   unique

  // default ctor
  SharedPtr() = default; // use in-class initializer to intialize members

  // ctor(raw pointer)
  SharedPtr(T *raw_ptr) : ptr(raw_ptr) {}

  // copy ctor
  SharedPtr(const SharedPtr &sptr)
      : ptr(sptr.ptr), ref_count(sptr.ref_count), deleter(sptr.deleter) {
    ++*ref_count; // add shared counter
  }

  // move ctor
  SharedPtr(SharedPtr &&sptr) noexcept /* don't forget noexcept */
      : ptr(sptr.ptr), ref_count(sptr.ref_count), deleter(sptr.deleter) {
    sptr.ptr = nullptr;
    sptr.ref_count = nullptr;
  }

  // swap
  void swap(SharedPtr &lhs, SharedPtr &rhs) {
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.ref_count, rhs.ref_count);
    swap(lhs.deleter, rhs.deleter);
  }

  // copy assignment
  SharedPtr &operator=(SharedPtr const &rhs) {
    // increment first to ensure safty for self-assignment
    ++*rhs.ref_count;
    decrement_and_destroy();
    ptr = rhs.ptr;
    ref_count = rhs.ref_count;
    deleter = rhs.deleter;
    return *this;
  }

  // move assignment
  SharedPtr &operator=(SharedPtr &&rhs) noexcept /* don't forget noexcept */ {
    swap(*this, rhs);
    rhs.decrement_and_destroy();
    return *this;
  }

  // convert to boolean value
  operator bool() const { return ptr; }
  // operator*() , dereference
  T &operator*() const { return *ptr; }

  // operator->() , arrow
  T *operator->() const {
    return ptr;
    // or:
    // return &*ptr;
    // equivalent but self-document
  }

  // note: don't forget to add const qualifier in operator* and operator->
  // 否則 const Blob 內原本使用到 shared_ptr 對應的操作的地方就會找不到這兩個
  // operators，因為 const member 不能 call nonconst function

  std::size_t use_count() const { return *ref_count; }

  T *get() const { return ptr; }

  bool unique() const { return 1 == *ref_count; }

  void reset() { decrement_and_destroy(); }
  void reset(T *raw_ptr) {
    if (ptr != raw_ptr) {
      decrement_and_destroy();
      ptr = raw_ptr;
      ref_count = new std::size_t(1);
    }
  }

  // dtor
  ~SharedPtr() { decrement_and_destroy(); }

private:
  T *ptr = nullptr;
  std::size_t *ref_count =
      new std::size_t(1); // at least one pointer points to the object
  std::function<void(T *)> deleter = Deleter();

  // private utility
  void decrement_and_destroy() {
    if (ptr && 0 == --*ref_count) {
      delete ref_count;
      deleter(ptr);
    } else if (!ptr) {
      delete ref_count;
    }
    ref_count = nullptr;
    ptr = nullptr;
  }
};

#endif