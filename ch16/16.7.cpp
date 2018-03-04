template <typename T, unsigned N> constexpr unsigned int size(T (&arr)[N]) {
  return N;
}

#include <iostream>

int main() {
  int arr[10];
  std::cout << size(arr) << std::endl;
}