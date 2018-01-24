#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::scanf;
using std::strcmp;
using std::string;
using std::strncat;
using std::strncpy;
using std::vector;
using std::getline;

int main() {
  string input;
  string cur_string;
  string largest_number_times_duplicate_string;
  int max_duplicate_times = 1;
  int cur_duplicate_times = 1;
  while (cin >> input) {
    if (input != cur_string) {
      cur_string = input;
      cur_duplicate_times = 1;
    } else {
      ++cur_duplicate_times;
      if (cur_duplicate_times > max_duplicate_times) {
        largest_number_times_duplicate_string = cur_string;
        max_duplicate_times = cur_duplicate_times;
      }
    }
  }
  if (max_duplicate_times == 1) {
    cout << "no duplicate strings" << endl;
  } else {
    cout << "max duplicate strings: " << largest_number_times_duplicate_string
         << endl;
    cout << "duplicate times: " << max_duplicate_times << endl;
  }

  return 0;
}