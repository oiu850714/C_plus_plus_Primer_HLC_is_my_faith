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
using std::scanf;
using std::strcmp;
using std::string;
using std::strncat;
using std::strncpy;
using std::vector;
using std::isupper;

// SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch06#exercise-66

// local variable: defined in function
// parameter: defined in function's parameter list
// local static variable: defined in function, initialized before the first
//      function execution, and lifetime continues across calls to the function

int func(int i) {     // i is parameter
  static int ctr = 0; // ctr is static
  return (ctr += i);
}

int main() {
  for (int i = 0; i <= 10; i++) // i is local variable
    cout << func(i) << endl;
}