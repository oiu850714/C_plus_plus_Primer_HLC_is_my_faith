#include <iostream>

int main() {
  std::cout << "UINT32_MAX: " << UINT32_MAX << std::endl;
  std::cout << "INT32_MAX: " << INT32_MAX << std::endl;
  unsigned u = 10, u2 = 42;
  std::cout << u2 - u << std::endl; // output 32
  std::cout
      << u - u2
      << std::endl; // output -32 mod (UINT32_MAX+1, i.e. 2^32), i.e. 4294967264
  int i = 10, i2 = 42;
  std::cout << i2 - i << std::endl; // output 32
  std::cout << i - i2 << std::endl; // output -32
  std::cout << i - u << std::endl;  // output 0
  std::cout << u - i << std::endl;  // output 0
}