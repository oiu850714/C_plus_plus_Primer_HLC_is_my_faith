// ex 16.55 it will not compile

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

// this version of print will be called for all but the last element in the pack
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args &... rest) {
  os << t << ", ";           // print the first argument
  return print(os, rest...); // recursive call; print the other arguments
}

template <typename T> ostream &print(ostream &os, const T &t) {
  return os << t; // no separator after the last element in the pack
}

int main() {
  char c_str[] = "C stytle string";
  string str = "C++ string";
  int i = 9487;
  double d = 94.87;

  print(cout, c_str) << endl;
  print(cout, c_str, str) << endl;
  print(cout, c_str, str, i, d) << endl;
}