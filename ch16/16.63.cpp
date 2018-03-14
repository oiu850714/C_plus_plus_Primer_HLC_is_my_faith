#include <cstring>
#include <iostream>
#include <string>
#include <vector>

template <typename T> size_t occur(const std::vector<T> &vec, T val) {
  size_t count = 0;
  for (const auto &e : vec) {
    count += e == val;
  }
  return count;
}

// ex 16.64
template <>
size_t occur(const std::vector<const char *> &vec, const char *val) {
  size_t count = 0;
  for (auto e : vec) {
    count += strcmp(e, val) == 0;
  }
  return count;
}

int main() {
  std::vector<int> ivec{9, 5, 3, 3, 9, 6, 7};
  std::vector<std::string> svec{"7", "5", "3", "3", "9", "6", "7"};
  std::vector<double> dvec{7.0, 5.0, 3.0, 3.0, 9.0, 6.0, 7.0, 8.7};
  std::cout << occur(ivec, 3) << std::endl;
  std::cout << occur(svec, std::string("7")) << std::endl;
  std::cout << occur(dvec, 8.7) << std::endl;

  std::vector<const char *> c_str_vec{"7", "5", "3", "3", "9", "6", "7"};
  std::cout << occur(c_str_vec, "3") << std::endl;
}