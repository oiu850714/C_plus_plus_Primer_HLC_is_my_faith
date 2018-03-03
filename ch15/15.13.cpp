#include <iostream>
#include <string>
using std::string;
using std::ostream;

class base {
public:
  string name() { return basename; }
  virtual void print(ostream &os) { os << basename; }

private:
  string basename;
};
class derived : public base {
public:
  void print(ostream &os) {
    // print(os);
    this->base::print(os); // should use scope operator
    // base::print(os); // or call base::print(os); directly
    os << " " << i;
  }

private:
  int i;
};