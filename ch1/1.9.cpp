#include <iostream>

int main() {
  int i = 50;
  int result = 0;
  while (i <= 100) {
    result += i;
    ++i;
  }
  std::cout << "sum(50 to 100): " << result << std::endl;
  return 0;
}