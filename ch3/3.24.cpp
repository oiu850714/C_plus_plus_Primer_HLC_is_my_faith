#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  vector<int> ivec;
  int temp = 0;
  while (cin >> temp) {
    ivec.push_back(temp);
  }

  if (ivec.size() == 0) {
    cout << "input at least one integer" << endl;
    return -1;
  }

  if (ivec.size() < 2) {
    cout << "there is only one element, no adjacent elements" << endl;
  } else {
    for (auto cit = ivec.cbegin(); cit != ivec.cend() - 1; cit++) {
      cout << *cit + *(cit + 1);
      cout << ((cit != ivec.cend() - 2) ? " " : "\n");
    }
  }

  for (auto left = ivec.cbegin(), right = ivec.cend() - 1; left <= right;
       left++, right--) {
    if (left != right) {
      cout << *left + *right << " ";
    } else {
      cout << *left; // case that there are odd elements
    }
  }
  cout << endl;
  return 0;
}