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
using std::scanf;
using std::strcmp;
using std::strncpy;
using std::strncat;

int main() {
  int C_array[9487] = {};
  vector<int> Cpp_vector(begin(C_array), end(C_array));

  for (decltype(Cpp_vector.size()) i = 0; i < Cpp_vector.size(); i++) {
    C_array[i] = Cpp_vector[i];
  }
}