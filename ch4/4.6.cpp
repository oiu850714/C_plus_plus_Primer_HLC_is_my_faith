#include <iostream>
int main() {
  int i = 9487;
  std::cout << (i % 2 ? "odd" : "even") << std::endl;
  std::cout << (i % 2 == 0 ? "even" : "odd") << std::endl;
  std::cout << (i & 0x1 ? "odd" : "even") << std::endl;
}