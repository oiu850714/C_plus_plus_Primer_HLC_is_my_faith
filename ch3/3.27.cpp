#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

int txt_size() {}

int main() {
  unsigned buf_size = 1024;
  //(a)
  int ia1[buf_size]; // illegal: buf_size is not const expression
  //(c)
  int ia2[txt_size()]; // illegal: txt_size() is not const expression
  //(b)
  int ia3[4 * 7 - 14]; // legal
  //(d)
  char st[11] =
      "fundamental"; // illegal: char array has no enough space for '\0'
}