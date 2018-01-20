#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::begin;
using std::end;
using std::scanf;
using std::strcmp;
using std::strncpy;
using std::strncat;

int main() {
  cout << "sizeof bool: " << sizeof(bool) << endl;
  cout << "sizeof char: " << sizeof(char) << endl;
  cout << "sizeof int: " << sizeof(int) << endl;
  cout << "sizeof long: " << sizeof(long) << endl;
  cout << "sizeof long long: " << sizeof(long long) << endl;
  cout << "sizeof float: " << sizeof(float) << endl;
  cout << "sizeof double: " << sizeof(double) << endl;
  cout << "sizeof long double: " << sizeof(long double) << endl;
  cout << "sizeof int*: " << sizeof(int *) << endl;
  cout << "sizeof int[10]: " << sizeof(int[10]) << endl;
  cout << "sizeof \"hsilu\": " << sizeof("hsilu") << endl;
  cout << "sizeof vector<int>: " << sizeof(vector<int>) << endl;
  cout << "sizeof vector<double>: " << sizeof(vector<double>) << endl;
  cout << "sizeof string: " << sizeof(string) << endl;
}