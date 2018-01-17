#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main() {
  int arr[1000];
  for (int *ptr = begin(arr); ptr != end(arr); ptr++) {
    *ptr = 0;
  }
  for (auto e : arr)
    cout << e << " ";
  cout << endl;
  return 0;
}