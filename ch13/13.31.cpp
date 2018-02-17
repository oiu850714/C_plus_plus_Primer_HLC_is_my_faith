#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class HasPtr {
  friend void swap(HasPtr &, HasPtr &);

public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &);
  // HasPtr &operator=(const HasPtr &);
  HasPtr &operator=(HasPtr);
  ~HasPtr();

  bool operator<(const HasPtr &rhs) { return *this->ps < *rhs.ps; }

private:
  std::string *ps;
  int i;
};

HasPtr::HasPtr(const HasPtr &ptr) : ps(new std::string(*ptr.ps)), i(ptr.i) {}
/*
HasPtr &HasPtr::operator=(const HasPtr &ptr) {
  if (this != &ptr) {
    delete ps;
    ps = new std::string(*ptr.ps);
    i = ptr.i;
  }
  return *this;
}
*/
HasPtr &HasPtr::operator=(HasPtr ptr) {
  swap(*this, ptr);
  return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
  std::cout << "use self-defined swap" << std::endl;
  using std::swap;
  swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
  swap(lhs.i, rhs.i);   // swap the int members
}

HasPtr::~HasPtr() { delete ps; }

using std::vector;
using std::string;
using std::sort;

int main() {
  vector<HasPtr> vec{string("5"), string("4"), string("3"), string("2"),
                     string("1")};
  sort(vec.begin(), vec.end());
}