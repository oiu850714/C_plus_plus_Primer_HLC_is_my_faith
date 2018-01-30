#include <iostream>
#include <list>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::list;

int main() {
  vector<int> vec_int{9, 4, 8, 7};
  list<int> list_int{8, 7, 9, 4};
  cout << (vec_int == vector<int>(list_int.begin(), list_int.end())) << endl;
}