#ifndef _16_16_VEC_H_
#define _16_16_VEC_H_

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <utility>
#include <vector>

template <typename T> class Vec {
  // global operators
  friend bool operator==(const Vec<T> &lhs, const Vec<T> &rhs) {
    if (lhs.size() != rhs.size())
      return false;
    for (auto l_it = lhs.begin(), r_it = rhs.begin(); l_it != rhs.end();
         ++l_it, ++r_it) {
      if (*l_it != *r_it)
        return false;
    }
    return true;
  }
  friend bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs == rhs);
  }
  friend bool operator<(const Vec<T> &lhs, const Vec<T> &rhs) {
    size_t size = (lhs.size() < rhs.size() ? lhs.size() : rhs.size());
    size_t index = 0;
    auto l_it = lhs.begin(), r_it = rhs.begin();
    for (; index != size; ++index) {
      if (*(l_it + index) == *(r_it + index))
        continue;
      else if (*(l_it + index) < *(r_it + index))
        return true;
      else
        return false;
    }
    return lhs.size() < rhs.size() ? true : false; // one if another's subVec
  }
  friend bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(rhs < lhs);
  }
  friend bool operator>(const Vec<T> &lhs, const Vec<T> &rhs) {
    return rhs < lhs;
  }
  friend bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs < rhs);
  }
  // end of global operators

public:
  using size_type = size_t;
  Vec()
      : // the allocator member is default initialized
        elements(nullptr),
        first_free(nullptr), cap(nullptr) {}
  Vec(const Vec<T> &);            // copy constructor
  Vec &operator=(const Vec<T> &); // copy assignment
  ~Vec();                         // destructor
  void push_back(const T &);      // copy the element
  void pop_back();
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  T *begin() const { return elements; }
  T *end() const { return first_free; }

  void resize(const size_t);
  void reserve(const size_t);

  Vec(const std::initializer_list<T> &);
  Vec(Vec<T> &&) noexcept;
  Vec &operator=(Vec<T> &&) noexcept;
  T &operator[](size_t n) { return elements[n]; }
  const T &operator[](size_t n) const {
    return elements[n];
  } // although return type could not be const, but it will not make same

private:
  static std::allocator<T> alloc; // allocates the elements
  void chk_n_alloc() // used by functions that add elements to a Vec
  {
    if (size() == capacity())
      reallocate();
  }
  // utilities used by the copy constructor, assignment operator, and destructor
  std::pair<T *, T *> alloc_n_copy(const T *, const T *);
  void alloc_n_move(const size_t); // refer to Mooophy's answer
  void free();                     // destroy the elements and free the space
  void reallocate(); // get more space and copy the existing elements
  T *elements;       // pointer to the first element in the array
  T *first_free;     // pointer to the first free element in the array
  T *cap;            // pointer to one past the end of the array

  void range_initailize(const T *,
                        const T *); // Vec(initializer_list&) and
                                    // Vec(Vec&) use exaclty same
                                    // code, so refactor
  void move_pointer(Vec<T> &) noexcept;
};

// allocmust be defined in the Vec implmentation file

template <typename T> std::allocator<T> Vec<T>::alloc;

template <typename T> void Vec<T>::push_back(const T &e) {
  chk_n_alloc(); // ensure that there is room for another element
  // construct a copy of s in the element to which first_free points
  alloc.construct(first_free++, e);
}

template <typename T> void Vec<T>::pop_back() {
  if (size()) {
    alloc.destroy(--first_free);
  }
}

template <typename T>
std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e) {
  // allocate space to hold as many elements as are in the range
  auto data = alloc.allocate(e - b);
  // initialize and return a pair constructed from data and
  // the value returned by uninitialized_copy
  return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T> void Vec<T>::free() {
  // may not pass deallocate a 0 pointer; if elements is 0, there’s no work to
  // do
  if (elements) {
    // // destroy the old elements in reverse order
    // for (auto p = first_free; p != elements; /* empty */)
    //   alloc.destroy(--p);

    std::for_each(elements, first_free,
                  [](T &s) { // parameter must be reference type
                    alloc.destroy(&s);
                  });
    // doesn't need to destroy the elements in reverse order now
    // and using STL is more general
    alloc.deallocate(elements, cap - elements);
  }
}

template <typename T>
void Vec<T>::range_initailize(const T *begin, const T *end) {
  auto newdata = alloc_n_copy(begin, end);
  elements = newdata.first;
  first_free = cap = newdata.second;
}

template <typename T> Vec<T>::Vec(const Vec<T> &vec) {
  // call alloc_n_copy to allocate exactly as many elements as in s
  range_initailize(vec.begin(), vec.end());
}

template <typename T> Vec<T>::Vec(const std::initializer_list<T> &il) {
  range_initailize(il.begin(),
                   il.end()); // Awesome!! il.begin() il.end() return T*
}

template <typename T> Vec<T>::~Vec() { free(); }

template <typename T> Vec<T> &Vec<T>::operator=(const Vec<T> &rhs) {
  // call alloc_n_copy to allocate exactly as many elements as in rhs
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

template <typename T> void Vec<T>::alloc_n_move(const size_t new_cap) {
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

template <typename T> void Vec<T>::reallocate() {
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

template <typename T> void Vec<T>::resize(const size_t n) {
  if (n > size()) {
    while (size() < n) {
      push_back(T());
    }
  } else if (n < size()) {
    while (size() > n) {
      pop_back();
    }
  }
}

template <typename T> void Vec<T>::reserve(const size_t new_cap) {
  // standard allows implementation to ignore reserve request lol
}

template <typename T> Vec<T>::Vec(Vec<T> &&vec) noexcept { move_pointer(vec); }

template <typename T> Vec<T> &Vec<T>::operator=(Vec<T> &&rhs) noexcept {
  if (this != &rhs) {
    free();
    move_pointer(rhs);
  }
  return *this;
}

template <typename T> void Vec<T>::move_pointer(Vec<T> &vec) noexcept {
  elements = vec.elements;
  first_free = vec.first_free;
  cap = vec.cap;
  vec.elements = vec.first_free = vec.cap = nullptr;
}

#endif