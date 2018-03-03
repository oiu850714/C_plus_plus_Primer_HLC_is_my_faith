#include <iostream>
#include <string>
using std::string;
using std::ostream;

class base {
public:
  string name() { return basename; }
  virtual void print(ostream &os) {
    os << "base\n";
    os << basename;
  }

private:
  string basename;
};
class derived : public base {
public:
  void print(ostream &os) {
    // print(os);
    os << "derived\n";
    this->base::print(os); // should use scope operator
    // base::print(os); // or call base::print(os); directly
    os << " " << i;
  }

private:
  int i;
};

int main() {
  base bobj;
  base *bp1 = &bobj;
  base &br1 = bobj;
  derived dobj;
  base *bp2 = &dobj;
  base &br2 = dobj;
  // I think it should pass parameter when calling print
  //(a)
  bobj.print(std::cout);
  // call on object, so determined at compile time;
  // call base::print

  //(b)
  dobj.print(std::cout);
  // call on object, so determined at compile time;
  // call derived::print

  //(c)
  bp1->name();
  // call through pointer, but function not virtual, so call base::name

  //(d)
  bp2->name();
  // call through pointer, but function not virtual, so call base::name

  //(e)
  br1.print(std::cout);
  // call through reference, and function virtual, so at runtime;
  // call base::print

  //(f)
  br2.print(std::cout);
  // call through reference, and function virtual, so at runtime;
  // call derived::print
}