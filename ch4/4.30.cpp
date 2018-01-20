#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::scanf;
using std::strcmp;
using std::string;
using std::strncat;
using std::strncpy;
using std::vector;

int main() {
  //(a)
  sizeof x + y;
  (sizeof x) + y;
  //(b)
  sizeof p->mem[i];
  sizeof(p->mem[i]); // -> and [] has higher precedence than sizeof
  //(c)
  sizeof a < b;
  (sizeof a) < b;
  //(d)
  sizeof f();
  sizeof(f());
}