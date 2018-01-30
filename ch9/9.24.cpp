#include <iostream>
#include <vector>

using std::vector;

int main() {
  vector<int> vec;
  std::cout << vec.front() << std::endl;
  std::cout << vec[0] << std::endl;
  std::cout << *vec.begin() << std::endl;
  std::cout << vec.at(0) << std::endl;
}