#include <cstdint> // INT32_MAX
#include <iostream>
// overflow occurs when the result of an expression cannot fit into the type of
// expression
// example
int main() {
  int i = INT32_MAX;
  std::cout << ++i << std::endl;
  return;
}