#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::isupper;
using std::scanf;
using std::strcmp;
using std::string;
using std::strncat;
using std::strncpy;
using std::vector;

//(a)
string f() { // return type should be std::string
  string s;  // ...
  return s;
}
//(b)
void f2(int i) {
  // functions that don't return value should add return type void at
  // definition
  /* .. . */
}
//(c)
int calc(int v1, int v2) {
  // need left brace, and parameters' name are the same
  /* ... */
  // and it should return int at somewhere
}
//(d)

double square(double x) { return x * x; } // should add block

int main() {}