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
  vector<int> v1; // empty vector, 0 elements
  //(b)
  vector<int> v2(10); // vector of 10 ints of value 0
  //(c)
  vector<int> v3(10, 42); // vector of 10 ints of value 42
  //(d)
  vector<int> v4{10}; // vector of 1 int of value 10
  //(e)
  vector<int> v5{10, 42}; // vector of 2 ints of value 10 and 42
  //(f)
  vector<string> v6{10}; // vector of 10 default empty strings
  //(g)
  vector<string> v7{10, "hi"}; // vector of 10 strings of value "hi"
}