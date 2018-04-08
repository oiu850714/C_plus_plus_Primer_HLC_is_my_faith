#include <iostream>
#include <string>

int main() {
  std::string s;
  s.reserve(200);
  // reserve 2 * 100 space to prevent string from allocating
  // 2 is just a magic number
  char c;
  while (std::cin >> c) {
    s.push_back(c);
  }
}