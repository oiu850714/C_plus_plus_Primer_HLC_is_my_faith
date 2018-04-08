#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::begin;
using std::end;

int main() {
  vector<char> cvec = {'1', '2', '3', '4'};
  string s(begin(cvec), end(cvec));
  std::cout << s << std::endl;
}