#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::getline;

int main() {
  vector<int> vec1(10, 9487);
  for (auto it = vec1.begin(); it != vec1.end(); it++) {
    *it = 2 * (*it);
  }
  for (auto it = vec1.cbegin(); it != vec1.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}