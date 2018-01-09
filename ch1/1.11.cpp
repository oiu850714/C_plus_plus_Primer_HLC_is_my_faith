#include <iostream>

int main() {
  std::cout
      << "Enter two numbers, I'll print numbers between these two numbers:";
  int i1 = 0;
  int i2 = 0;
  std::cin >> i1 >> i2;
  while (i1 <= i2) {
    std::cout << i1++ << std::endl;
  }
  return 0;
}