#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  vector<int> vec{9, 4, 8, 7, 9, 4, 5, 6, 6, 6, 9, 8, 8};
  for (auto r_it = vec.end() - 1; r_it >= vec.begin(); --r_it) {
    cout << *r_it << " ";
  }
  cout << endl;
}