#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

int main() {
  vector<int> ivec;
  ivec[0] = 42;
  // illegal: undefined behavoir

  vector<int> ivec2;
  ivec2.push_back(42);
  // use push_beck
}