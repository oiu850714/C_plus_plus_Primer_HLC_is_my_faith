#include <iostream>
using std::cout;
using std::endl;
void f() { cout << "f()" << endl; }
void f(int) { cout << "f(int)" << endl; }
void f(int, int) { cout << "f(int, int)" << endl; }
void f(double, double = 3.14) { cout << "f(double, double = 3.14)" << endl; }

int main() {
  //(a)
  // f(2.56, 42);
  // viable functions: f(int, int); and f(double, double = 3.14);
  // f(double, double = 3.14) match 2.56 better than other viable functions
  // f(int, int) match 42 betther than other viable functions
  // so this is an ambiguous call

  // f(2.56, 42) is compile error, replace with f()
  f();

  //(b)
  f(42);
  // viable functions: f(int); and f(double, double = 3.14);
  // f(int) match 42 better than other viable functions
  // not ambiguous call

  //(c)
  f(42, 0);
  // by same rule, f(int, int) is best match, no ambiguous
  //(d)
  f(2.56, 3.14);
  // f(double, double = 3.14) is best match, no ambiguous
}