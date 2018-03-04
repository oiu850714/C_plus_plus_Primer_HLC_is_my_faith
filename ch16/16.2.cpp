template <typename T> int compare(const T &t1, const T &t2) {
  if (t1 < t2)
    return -1;
  if (t2 < t1)
    return 1;
  return 0;
}

#include <iostream>

int main() {
  // int compare(const int&, const int&)
  std::cout << compare(94, 87) << std::endl;
  std::cout << compare(87, 94) << std::endl;
  std::cout << compare(87, 87) << std::endl;
  // int compare(const double&, const double&)
  std::cout << compare(9.4, 8.7) << std::endl;
  std::cout << compare(8.7, 9.4) << std::endl;
  std::cout << compare(8.7, 8.7) << std::endl;
  // int compare(const long&, const long&)
  std::cout << compare(97L, 87L) << std::endl;
}