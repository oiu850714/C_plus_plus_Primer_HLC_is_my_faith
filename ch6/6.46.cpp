#include <string>
using std::string;
inline bool isShorter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}

// no, isShorter cannot be declared as constexpr
// although that s1 and s2 is reference to const string
// it is at runtime that string's size can be known
// below is an example that const built-in cannot be determined at compile time

#include <iostream>
int main() {
  int i;
  std::cin >> i;
  const int j = i; // j is not constexpr
}