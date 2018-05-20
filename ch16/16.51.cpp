#include <iostream>
#include <string>
using std::cout;
using std::string;

template <typename T, typename... Args>
void foo(const T &t, const Args &... args) {
  cout << sizeof...(Args) << "\n";
  cout << sizeof...(args) << "\n";
}

int main() {
  int i = 0;
  double d = 3.14;
  string s = "how now brown cow";
  foo(i, s, 42, d); // three parameters in the pack
  foo(s, 42, "hi"); // two parameters in the pack
  foo(d, s);        // one parameter in the pack
  foo("hi");        // empty pack

  // output:
  // 3
  // 3
  // 2
  // 2
  // 1
  // 1
  // 0
  // 0
}