#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main() {
  vector<int> vec1{9, 4, 8, 7}, vec2{8, 7, 9, 4};
  cout << (vec1 == vec2) << endl;
}