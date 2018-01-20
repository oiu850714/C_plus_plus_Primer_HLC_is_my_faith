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
  vector<int> vec(100, 0);
  //(a)
  *vec.begin();
  /* * : dereference operator;
   * . : member selector;
   * (): call operator;
   *
   * when applying to vec, . has higher precedence than *,
   * so *vec.begin(); is *(vec.begin());
   * when applying to begin, () has same precedence with .,
   * but they are left associative,
   * so *(vec.begin()); is *((vec.begin)());
   *
   */
  //(b)
  *vec.begin() + 1;
  /* * : dereference operator;
   * . : member selector;
   * (): call operator;
   * + : arithmetic add operator;
   * when applying to vec, . has higher precedence than *,
   * so *vec.begin() + 1; is *(vec.begin()) + 1;
   * when applying to begin, () has same precedence with .,
   * but they are left associative,
   * so *(vec.begin()) + 1; is *((vec.begin)()) + 1;
   */
}