// ex 16.54 compiler will burst error
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::ostream;
using std::string;
template <typename T> ostream &print(ostream &os, const T &t) {
  return os << t; // no separator after the last element in the pack
}
// this version of print will be called for all but the last element in the pack
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args &... rest) {
  os << t << ", ";           // print the first argument
  return print(os, rest...); // recursive call; print the other arguments
}

#include <vector>
using std::vector;
int main() { print(cout, 9487, vector<int>()) << endl; }