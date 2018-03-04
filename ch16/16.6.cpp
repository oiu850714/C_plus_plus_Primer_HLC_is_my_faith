template <typename T, unsigned int N> T *begin(T (&arr)[N]) { return arr; }
template <typename T, unsigned int N> T *end(T (&arr)[N]) { return arr + N; }
//                                           ^ doesn't need to add const
// when passing const array to begin/end, T will automatically be const

#include <iostream>

int main() {
  int arr1[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const int arr2[10]{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  std::cout << *begin(arr1) << std::endl;
  std::cout << *end(arr1) << std::endl; // just demo, print *end() will be UB
  std::cout << *begin(arr2) << std::endl;
  std::cout << *end(arr2) << std::endl; // just demo, print *end() will be UB
}