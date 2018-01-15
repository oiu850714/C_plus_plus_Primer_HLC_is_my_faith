#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

int main() {
  vector<int> intv;
  int temp{0};
  while (cin >> temp)
    intv.push_back(temp);
}