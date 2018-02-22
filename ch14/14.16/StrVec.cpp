#include "StrVec.h"
#include <algorithm>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>
#include <vector>

using std::allocator;
using std::initializer_list;
using std::pair;
using std::string;
using std::for_each;
// allocmust be defined in the StrVec implmentation file
allocator<string> StrVec::alloc;

void StrVec::push_back(const string &s) {
  chk_n_alloc(); // ensure that there is room for another element
  // construct a copy of s in the element to which first_free points
  alloc.construct(first_free++, s);
}

void StrVec::pop_back() {
  if (size()) {
    alloc.destroy(--first_free);
  }
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b,
                                              const string *e) {
  // allocate space to hold as many elements as are in the range
  auto data = alloc.allocate(e - b);
  // initialize and return a pair constructed from data and
  // the value returned by uninitialized_copy
  return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
  // may not pass deallocate a 0 pointer; if elements is 0, there’s no work to
  // do
  if (elements) {
    // // destroy the old elements in reverse order
    // for (auto p = first_free; p != elements; /* empty */)
    //   alloc.destroy(--p);

    // ex 13.43
    for_each(elements, first_free,
             [](string &s) { // parameter must be reference type
               alloc.destroy(&s);
             });
    // doesn't need to destroy the elements in reverse order now
    // and using STL is more general
    alloc.deallocate(elements, cap - elements);
  }
}

void StrVec::range_initailize(const string *begin, const string *end) {
  auto newdata = alloc_n_copy(begin, end);
  elements = newdata.first;
  first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &s) {
  // call alloc_n_copy to allocate exactly as many elements as in s
  range_initailize(s.begin(), s.end());
}

StrVec::StrVec(const initializer_list<string> &il) {
  range_initailize(il.begin(),
                   il.end()); // Awesome!! il.begin() il.end() return string*
}
StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs) {
  // call alloc_n_copy to allocate exactly as many elements as in rhs
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

void StrVec::alloc_n_move(const size_t new_cap) {
  auto newdata = alloc.allocate(new_cap);
  auto dest = newdata;
  auto elem = elements;
  for (size_t i = 0; i != size();
       ++i) // copy old size() elements to memory pointed by newdata
    alloc.construct(dest++, std::move(*elem++));
  // after loop, dest - newdata == old size(), size() remain unchanged but
  // capacity change
  free();

  elements = newdata;
  first_free = dest;
  cap = newdata + new_cap;
}

void StrVec::reallocate() {
  // we’ll allocate space for twice as many elements as the current size
  auto newcapacity = size() ? 2 * size() : 1;
  // allocate new memory
  auto newdata = alloc.allocate(newcapacity);
  // move the data from the old memory to the new
  auto dest = newdata;  // points to the next free position in the new array
  auto elem = elements; // points to the next element in the old array
  for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
  free(); // free the old space once we’ve moved the elements
  // update our data structure to point to the new elements
  elements = newdata;
  first_free = dest;
  cap = elements + newcapacity;
}

void StrVec::resize(const size_t n) {
  if (n > size()) {
    while (size() < n) {
      push_back(string());
    }
  } else if (n < size()) {
    while (size() > n) {
      pop_back();
    }
  }
}

void StrVec::reserve(const size_t new_cap) {
  if (capacity() < new_cap) {
  }
}

// ex 13.49
StrVec::StrVec(StrVec &&vec) noexcept { move_pointer(vec); }

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
  if (this != &rhs) {
    free();
    move_pointer(rhs);
  }
  return *this;
}

void StrVec::move_pointer(StrVec &vec) noexcept {
  elements = vec.elements;
  first_free = vec.first_free;
  cap = vec.cap;
  vec.elements = vec.first_free = vec.cap = nullptr;
}

// ex 14.16
bool operator==(const StrVec &lhs, const StrVec &rhs) {
  if (lhs.size() != rhs.size())
    return false;
  for (auto l_it = lhs.begin(), r_it = rhs.begin(); l_it != rhs.end();
       ++l_it, ++r_it) {
    if (*l_it != *r_it)
      return false;
  }
  return true;
  /* // or you can use std::equal
  return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(),
  rhs.begin()));
  */
}
bool operator!=(const StrVec &lhs, const StrVec &rhs) { return !(lhs == rhs); }