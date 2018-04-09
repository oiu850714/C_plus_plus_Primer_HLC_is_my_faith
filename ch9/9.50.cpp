#include <string>
#include <vector>

using std::vector;
using std::string;
using std::stoi;
int64_t sum_integral(const vector<string> &svec) {
  int64_t i = 0;
  for (const auto &str : svec) {
    i += stoi(str);
  }
  return i;
}

double sum_floating(const vector<string> &svec) {
  double i = 0;
  for (const auto &str : svec) {
    i += stod(str);
  }
  return i;
}

#include <iostream>

int main() {
  vector<string> vec1{"1", "2", "3", "4", "5"};
  vector<string> vec2{"1.1", "2.2", "3.3", "4.4", "5.5"};
  std::cout << sum_integral(vec1) << std::endl;
  std::cout << sum_floating(vec2) << std::endl;
}