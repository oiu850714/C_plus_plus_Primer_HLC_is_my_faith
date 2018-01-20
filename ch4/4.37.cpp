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
  int i;
  double d;
  const string *ps;
  char *pc;
  void *pv;
  //(a)
  pv = (void *)ps;
  pv = static_cast<void *>(const_cast<string *>(ps)); // lol......
  //(b)
  i = int(*pc);
  i = static_cast<int>(*pc);
  //(c)
  pv = &d;
  pv = static_cast<void *>(&d);
  //(d)
  pc = (char *)pv;
  pc = static_cast<char *>(pv);
}