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
  vector<int> ivec1 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
  vector<int> ivec2(10, 42);
  vector<int> ivec3;
  for (int i = 0; i < 10; i++)
    ivec3.push_back(10);
  // prefer ivec2, because its code is shorter!
}