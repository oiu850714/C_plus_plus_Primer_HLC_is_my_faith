#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

void check_and_print(const vector<int> &vec) {
  if (vec.size() == 0) {
    cout << "vector empty" << endl;
    return;
  } else {
    cout << "vector's content: ";
    for (auto it = vec.cbegin(); it != vec.cend(); ++it)
      cout << *it << ", ";
    cout << endl;
  }
}

void check_and_print(const vector<string> &vec) {
  if (vec.size() == 0) {
    cout << "vector empty" << endl;
    return;
  } else {
    cout << "vector's content: ";
    for (auto it = vec.cbegin(); it != vec.cend(); ++it)
      cout << *it << ", ";
    cout << endl;
  }
}

int main() {
  vector<int> v1;              // empty vector, 0 elements
  vector<int> v2(10);          // vector of 10 ints of value 0
  vector<int> v3(10, 42);      // vector of 10 ints of value 42
  vector<int> v4{10};          // vector of 1 int of value 10
  vector<int> v5{10, 42};      // vector of 2 ints of value 10 and 42
  vector<string> v6{10};       // vector of 10 default empty strings
  vector<string> v7{10, "hi"}; // vector of 10 strings of value "hi"

  check_and_print(v1);
  check_and_print(v2);
  check_and_print(v3);
  check_and_print(v4);
  check_and_print(v5);
  check_and_print(v6);
  check_and_print(v7);
}