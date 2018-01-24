#include <cctype>
#include <cstdio>
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::isupper;
using std::scanf;
using std::strcmp;
using std::string;
using std::strncat;
using std::strncpy;
using std::vector;
using std::initializer_list;

void print_vec(vector<int>::iterator begin, vector<int>::iterator end) {
  if (begin != end) {
    cout << *begin << " ";
    return print_vec(begin + 1, end);
  }
  cout << endl;
  return;
}

int main() {
  vector<int> ivec{9, 4, 8, 7, 6, 6, 6, 7, 6};
  print_vec(begin(ivec), end(ivec));
}