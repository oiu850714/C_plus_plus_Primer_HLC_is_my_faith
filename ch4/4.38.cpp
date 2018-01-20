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
  int i = 94, j = 87;
  double slope = static_cast<double>(j / i);
  // evaluate j/i, integer division, first then cast the result to double
  cout << slope << endl;

  // another code to check the named-cast's behavior
  slope = static_cast<double>(j) / i;
  cout << slope << endl;

  int *p = reinterpret_cast<int *>(&slope);
  cout << *p << endl;
  int *pi = (int *)&slope;
  cout << *pi << endl;
  // above four lines very shitty
}