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

bool is_contain_capital(const string &s) { // if we don't modify argument by
                                           // reference, declare as const T&
  for (auto c : s) {
    if (isupper(c))
      return true;
  }
  return false;
}

string &
to_lower(string &s) { // we modify argument by reference, so declare as T&
  for (auto &c : s)
    c = tolower(c);
  return s;
}

int main() {
  string input_str;
  cin >> input_str;
  cout << "Has capital: " << (is_contain_capital(input_str) ? "true" : "false")
       << endl;
  cout << "To lower: " << to_lower(input_str) << endl;
  return 0;
}