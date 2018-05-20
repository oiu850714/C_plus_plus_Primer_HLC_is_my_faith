// ex 16.59

#include "StrVec.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main() {
  StrVec vec{string("1"), string("2"), string("3")};
  // ex 16.59
  string s = "hsiluSoCute";
  vec.emplace_back(s);
  // instantiate StrVec::emplace_back(string&);, which calls
  // allocator::construct(string&), which calls string's copy ctor
  for (size_t i = 0; i < vec.size(); i++)
    cout << vec[i] << " ";
  cout << endl;
}