// COPY FROM ex 14.26

#ifndef _STRVEC_H_
#define _STRVEC_H_
// exact copy of 13.40.cpp, just for convenience

#include <initializer_list>
#include <memory>
#include <string>
#include <utility>
#include <vector>
// simplified implementation of the memory allocation strategy for a vector-like
// class

// ex 14.16
class StrVec;
bool operator==(const StrVec &, const StrVec &);
bool operator!=(const StrVec &, const StrVec &);

// ex 14.18
bool operator<(const StrVec &, const StrVec &);
bool operator<=(const StrVec &, const StrVec &);
bool operator>(const StrVec &, const StrVec &);
bool operator>=(const StrVec &, const StrVec &);

class StrVec {
  // ex 14.16
  friend bool operator==(const StrVec &, const StrVec &);
  friend bool operator!=(const StrVec &, const StrVec &);

  // ex 14.18
  friend bool operator<(const StrVec &, const StrVec &);
  friend bool operator<=(const StrVec &, const StrVec &);
  friend bool operator>(const StrVec &, const StrVec &);
  friend bool operator>=(const StrVec &, const StrVec &);

public:
  using size_type = size_t;
  StrVec()
      : // the allocator member is default initialized
        elements(nullptr),
        first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec &);              // copy constructor
  StrVec &operator=(const StrVec &);   // copy assignment
  ~StrVec();                           // destructor
  void push_back(const std::string &); // copy the element
  void pop_back();                     // ex 13.39
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; } // ex 13.39
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }

  void resize(const size_t); // ex 13.39
  void reserve(const size_t);

  StrVec(const std::initializer_list<std::string> &); // ex 13.40

  // ex 13.49
  StrVec(StrVec &&) noexcept;
  StrVec &operator=(StrVec &&) noexcept;

  // ex 14.26
  std::string &operator[](size_t n) { return elements[n]; }
  const std::string &operator[](size_t n) const {
    return elements[n];
  } // although return type could not be const, but it will not make same

  // ex 16.58
  template <class... Args> void emplace_back(Args &&... args);

private:
  static std::allocator<std::string> alloc; // allocates the elements
  void chk_n_alloc() // used by functions that add elements to a StrVec
  {
    if (size() == capacity())
      reallocate();
  }
  // utilities used by the copy constructor, assignment operator, and destructor
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  void alloc_n_move(const size_t); // refer to Mooophy's answer
  void free();                     // destroy the elements and free the space
  void reallocate();       // get more space and copy the existing elements
  std::string *elements;   // pointer to the first element in the array
  std::string *first_free; // pointer to the first free element in the array
  std::string *cap;        // pointer to one past the end of the array

  void
  range_initailize(const std::string *,
                   const std::string *); // StrVec(initializer_list&) and
                                         // StrVec(StrVec&) use exaclty same
                                         // code, so refactor

  // ex 13.49
  void move_pointer(StrVec &) noexcept;
};

// ex 16.58
template <class... Args> inline void StrVec::emplace_back(Args &&... args) {
  chk_n_alloc(); // reallocates the StrVec ifnecessary
  alloc.construct(first_free++, std::forward<Args>(args)...);
}

#endif