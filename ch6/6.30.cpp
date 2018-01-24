#include <cctype>
#include <cstdio>
#include <cstring>
#include <initializer_list>
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
using std::initializer_list;

// incorrect return values, this code will not compile
bool str_subrange(const string &str1, const string &str2) {
  // same sizes: return normal equality test
  if (str1.size() == str2.size())
    return str1 == str2; // ok: == returns bool
  // find the size of the smaller string; conditional operator, see § 4.7 (p.
  // 151)
  auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
  // look at each element up to the size ofthe smaller string
  for (decltype(size) i = 0; i != size; ++i) {
    if (str1[i] != str2[i])
      return false; // error #1: no return value; compiler should detect this
                    // error
  }
  // error #2: control might flow off the end ofthe function without a return //
  // the compiler might not detect this error
}
// g++7.2 with option -Wall will warning error #2