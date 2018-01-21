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

extern bool find(string word);

int main() {

  //(a)
  // origin:
  //   while (string::iterator iter != s.end()) {   // error: iter should be
  //     /* ... */                                  // declared before while
  //   }                                            // loop

  // correct:
  string s;
  auto iter = s.begin();
  while (iter != s.end()) {
    /* ... */
  }

  //(b)
  // origin:
  //   while (bool status = find(word)) {
  //     /* .. . */
  //   }
  //   if (!status) { //error: status if out of scope
  //     /* .. . */
  //   }

  // correct:
  string word;
  bool status;
  while ((status = find(word))) { /* .. . */
  }
  if (!status) {
    /* .. . */
  }
}