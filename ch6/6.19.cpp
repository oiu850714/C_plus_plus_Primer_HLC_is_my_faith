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

double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

int main() {
  //(a)
  // calc(23.4, 55.1); // calc only has one parameter
  //(b)
  count("abcda", 'a'); // legal, string literal can be converted to string
  //(c)
  calc(66); // legal, int can be converted to doubleee
  //(d)
  sum(vec.begin(), vec.end(), 3.8); // legal
}

double calc(double) {}
int count(const string &, char) {}
int sum(vector<int>::iterator, vector<int>::iterator, int) {}
