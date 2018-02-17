#include <iostream>
#include <string>

class HasPtr {
  friend void swap(HasPtr &, HasPtr &);

public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &);
  // HasPtr &operator=(const HasPtr &);
  HasPtr &operator=(HasPtr);
  ~HasPtr();

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

int main() {
  HasPtr p1("hsilu"), p2;
  p2 = p1;
}