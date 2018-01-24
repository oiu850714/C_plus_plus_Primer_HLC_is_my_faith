#include <cctype>
#include <cstdio>
#include <cstring>
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
using std::tolower;

void print(const int ia[10]) {
  for (size_t i = 0; i != 10; ++i)
    cout << ia[i] << endl;
}

// SEE:
// https://stackoverflow.com/questions/26530659/confused-about-array-parameters
// the size declared in ia is irrelevant
// const int ia[10] is really a const int*
// so if we pass an array of size less than 10, it's UB
// it can be documented that the API receive array of size at least 10
