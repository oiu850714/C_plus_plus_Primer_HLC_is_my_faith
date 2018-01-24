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

extern int get_response();

int main() {
  //(a)
  do { // need add brackets
    int v1, v2;
    cout << "Please enter two numbers to sum:";
    if (cin >> v1 >> v2)
      cout << "Sum is: " << v1 + v2 << endl;
  } while (cin);
  //(b)

  int ival;
  do {                             // ...
  } while (ival = get_response()); // cannot use declaration expression in do
                                   // while condition
  //(c)
  int ival2;
  do {
    ival2 = get_response();
  } while (ival2); // condition must use variable outside do while scope