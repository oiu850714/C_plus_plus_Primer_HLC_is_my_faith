#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &);
  HasPtr &operator=(const HasPtr &);
  ~HasPtr();

private:
  std::string *ps;
  int i;
};

HasPtr::HasPtr(const HasPtr &ptr) : ps(new std::string(*ptr.ps)), i(ptr.i) {}
HasPtr &HasPtr::operator=(const HasPtr &ptr) {
  if (this != &ptr) {
    delete ps;
    ps = new std::string(*ptr.ps);
    i = ptr.i;
  }
  return *this;
}

HasPtr::~HasPtr() { delete ps; }