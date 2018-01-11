#include <iostream>

int main() {
  int *ptr = nullptr;
  int i = 42;
  std::cout << "ptr: " << ptr << " i: " << i << std::endl;
  ptr = &i;
  *ptr = 9487;
  std::cout << "ptr: " << ptr << " i: " << i << std::endl;
  return 0;
}