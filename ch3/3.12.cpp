#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

int main() {
  //(a)
  vector<vector<int>> ivec; // legal: create a vector of vector of int
  //(b)
  vector<string> svec1 = ivec; // illegal: initailizer's type not match
  //(c)
  vector<string> svec2(10, "null");
  // legal: create a vector of ten strings of value "null"
}