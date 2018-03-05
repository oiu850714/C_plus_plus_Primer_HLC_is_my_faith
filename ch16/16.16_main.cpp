#include "16.16_Vec.h"
#include <iostream>

int main() {
  Vec<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << vec[9] << std::endl;
  vec.push_back(87);
  std::cout << vec[10] << std::endl;
  Vec<int> vec2;
  vec2 = vec;
  std::cout << (vec2 == vec ? "vec == vec2" : "vec != vec2") << std::endl;
  vec2.push_back(1000);
  std::cout << (vec2 > vec ? "vec > vec2" : "vec <= vec2") << std::endl;

  std::cout << "vec2.size(): " << vec2.size() << std::endl;
  std::cout << "vec2.capacity(): " << vec2.capacity() << std::endl;
  std::cout << "*vec2.begin(): " << *vec2.begin() << std::endl;
  std::cout << "*vec2.end(): " << *vec2.end() << std::endl;

  vec2.resize(20);
  std::cout << "after resize, vec2.capacity(): " << vec2.capacity()
            << std::endl;
  std::cout << "vec2.size(): " << vec2.size() << std::endl;
}