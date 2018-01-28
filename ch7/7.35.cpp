#include <iostream>
#include <string>
#include <vector>
using std::string;

// SEE:
// https://github.com/huangmingchuan/Cpp_Primer_Answers/tree/master/ch07#%E7%BB%83%E4%B9%A0735
typedef double Type;
Type initVal(); // use string
class Exercise {
public:
  typedef double Type; // error, but compiler will not complain
  Type setVal(Type);
  Type initVal();

private:
  int val;
};

Type Exercise::setVal(Type parm) {
  val = parm + initVal();
  return val;
}

/*
typedef double Money;
class Account {
public:
  Money balance() { return bal; } // uses Money from the outer scope
private:
  typedef double Money; // error: cannot redefine Money
  Money bal;
};
*/