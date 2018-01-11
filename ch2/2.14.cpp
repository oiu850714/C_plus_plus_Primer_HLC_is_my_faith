#include <iostream>

// program legal, output 100 55
// but such naming is considered as bad practice
int main() {
  int i = 100, sum = 0;
  for (int i = 0; i != 10; ++i)
    sum += i;
  std::cout << i << " " << sum << std::endl;
}