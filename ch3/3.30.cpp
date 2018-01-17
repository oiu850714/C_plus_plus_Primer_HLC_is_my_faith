#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

int main() {
  constexpr size_t array_size = 10;
  int ia[array_size];
  for (size_t ix = 1; ix <= array_size /*out of range when ix == 10*/; ++ix)
    ia[ix] = ix;
}