#ifndef _13_39_H_
#define _13_39_H_

#include <memory>
#include <string>
#include <utility>
#include <vector>
// simplified implementation of the memory allocation strategy for a vector-like
// class
class StrVec {
public:
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
};

#endif