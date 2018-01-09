#include <iostream>

int main() {
  int sum = 0;
  for (int i = -100; i <= 100; ++i)
    sum += i;
  std::cout << sum << std::endl;
}
/*
 * it iterates from i = -100 to i = 100
 * and add i to sum on each iteration
 * the final value of sum = 0
 */