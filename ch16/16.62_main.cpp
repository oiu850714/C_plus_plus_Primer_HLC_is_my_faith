#include "16.62.h"
#include <iostream>
#include <unordered_set>
using std::unordered_set;
int main() {
  unordered_set<Sales_data> SDset;
  SDset.insert(std::cin);
  SDset.insert(std::cin);
  SDset.insert(std::cin);
  SDset.insert(std::cin);

  for (auto &b : SDset) {
    std::cout << b << std::endl;
  }
}