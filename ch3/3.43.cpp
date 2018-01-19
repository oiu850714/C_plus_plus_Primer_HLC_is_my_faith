#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::begin;
using std::end;
using std::cbegin;
using std::cend;
using std::scanf;
using std::strcmp;
using std::strncpy;
using std::strncat;

int main() {
  int ia[3][4]{{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};

  for (const auto &inner_arr : ia) {
    for (const auto &e : inner_arr) {
      cout << e << " ";
    }
    cout << endl;
  }
  cout << endl;

  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 4; j++) {
      cout << ia[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  for (auto inner_arr_p = cbegin(ia); inner_arr_p != cend(ia); inner_arr_p++) {
    for (auto element_p = cbegin(*inner_arr_p); element_p != cend(*inner_arr_p);
         element_p++) {
      cout << *element_p << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}