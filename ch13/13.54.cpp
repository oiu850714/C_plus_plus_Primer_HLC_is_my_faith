#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class HasPtr {
  friend void swap(HasPtr &, HasPtr &);

public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &);
  HasPtr(HasPtr &&) noexcept;
  HasPtr &operator=(HasPtr);
  HasPtr &operator=(HasPtr &&);
  ~HasPtr();

  bool operator<(const HasPtr &rhs) { return *this->ps < *rhs.ps; }

private:
  std::string *ps;
  int i;
};

HasPtr::HasPtr(const HasPtr &ptr) : ps(new std::string(*ptr.ps)), i(ptr.i) {}
HasPtr::HasPtr(HasPtr &&hp) noexcept : ps(hp.ps), i(hp.i) { hp.ps = nullptr; }
HasPtr &HasPtr::operator=(HasPtr ptr) {
  swap(*this, ptr);
  return *this;
}

// ex 13.54: define move assignment directly
HasPtr &HasPtr::operator=(HasPtr &&rhs) {
  ps = rhs.ps;
  i = rhs.i;
  rhs.ps = nullptr;
  return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
  swap(lhs.i, rhs.i);   // swap the int members
}

HasPtr::~HasPtr() { delete ps; }

int main() {
  HasPtr p1;
  p1 = HasPtr("www");
  // class member definition will not cause error,
  // function matching causes error.
}