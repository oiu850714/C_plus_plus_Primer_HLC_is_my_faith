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

string
make_plural(size_t ctr, const string &word,
            const string &ending = "s") { // I think the "second" parameter
                                          // should be "word", but it seems
                                          // that others' answer's "second"
                                          // parameter is "ending"...
  return (ctr > 1) ? word + ending : word;
}

int main() {
  cout << make_plural(1, "success") << endl;
  cout << "default plural: " << make_plural(2, "success") << endl;
  cout << "not use default plural: " << make_plural(2, "success", "es") << endl;
  cout << make_plural(1, "failure") << endl;
  cout << "default plural: " << make_plural(2, "failure") << endl;
  cout << "not use default plural: " << make_plural(2, "failure", "s") << endl;
}