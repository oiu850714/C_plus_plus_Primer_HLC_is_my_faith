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
  cout << "v1's size: " << v1.size() << endl;
  cout << "v1's content: ";
  if (!v1.size())
    cout << "no content" << endl;
  else {
    for (auto &e : v1)
      cout << e << ", ";
    cout << endl;
  }
  //(b)
  vector<int> v2(10); // vector of 10 ints of value 0
  cout << "v2's size: " << v2.size() << endl;
  cout << "v2's content: ";
  if (!v2.size())
    cout << "no content" << endl;
  else {
    for (auto &e : v2)
      cout << e << ", ";
    cout << endl;
  }
  //(c)
  vector<int> v3(10, 42); // vector of 10 ints of value 42
  cout << "v3's size: " << v3.size() << endl;
  cout << "v3's content: ";
  if (!v3.size())
    cout << "no content" << endl;
  else {
    for (auto &e : v3)
      cout << e << ", ";
    cout << endl;
  }
  //(d)
  vector<int> v4{10}; // vector of 1 int of value 10
  cout << "v4's size: " << v4.size() << endl;
  cout << "v4's content: ";
  if (!v4.size())
    cout << "no content" << endl;
  else {
    for (auto &e : v4)
      cout << e << ", ";
    cout << endl;
  }
  //(e)
  vector<int> v5{10, 42}; // vector of 2 ints of value 10 and 42
  cout << "v5's size: " << v5.size() << endl;
  cout << "v5's content: ";
  if (!v5.size())
    cout << "no content" << endl;
  else {
    for (auto &e : v5)
      cout << e << ", ";
    cout << endl;
  }
  //(f)
  vector<string> v6{10}; // vector of 10 default empty strings
  cout << "v6's size: " << v6.size() << endl;
  cout << "v6's content: ";
  if (!v6.size())
    cout << "no content" << endl;
  else {
    for (auto &e : v6)
      cout << e << ", ";
    cout << endl;
  }
  //(g)
  vector<string> v7{10, "hi"}; // vector of 10 strings of value "hi"
  cout << "v7's size: " << v7.size() << endl;
  cout << "v7's content: ";
  if (!v7.size())
    cout << "no content" << endl;
  else {
    for (auto &e : v7)
      cout << e << ", ";
    cout << endl;
  }
}