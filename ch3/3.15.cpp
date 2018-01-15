#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

int main() {
  vector<string> stringv;
  string temp;
  while (cin >> temp)
    stringv.push_back(temp);
}