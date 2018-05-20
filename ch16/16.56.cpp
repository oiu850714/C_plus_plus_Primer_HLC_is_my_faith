#include <iostream>
#include <sstream>
#include <string>

using std::ostream;
using std::ostringstream;
using std::string;

// See
// https://github.com/Mooophy/Cpp-Primer/blob/master/ch16/ex16.56.57/main.cpp or
// Primer to overload debug_rep
template <typename T> string debug_rep(const T &t) {
  ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename T> ostream &print(ostream &os, const T &t) {
  return os << t; // no separator after the last element in the pack
}
// this version of print will be called for all but the last element in the pack
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args &... rest) {
  os << t << ", ";           // print the first argument
  return print(os, rest...); // recursive call; print the other arguments
}

template <typename... Args>
ostream &errorMsg(ostream &os, const Args &... rest) {
  return print(os, debug_rep(rest)...);
}

int main() {
  errorMsg(std::cout, 1, 2, 3, 4, "C string", string("C++ string"), 94.87);
}