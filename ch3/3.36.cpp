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
  vector<int> v1, v2;
  cout << ((v1 == v2) ? "equal" : "not equal") << endl;

  int arr1[100] = {}, arr2[101] = {};

  int *ptr1 = begin(arr1), *ptr2 = begin(arr2);
  if (end(arr1) - ptr1 !=
      end(arr2) - ptr2) { // if arrays' size are different, then different
    cout << "not equal" << endl;
  } else {
    for (; ptr1 != end(arr1) && *ptr1++ == *ptr2++;)
      ;
    cout << ((ptr1 == end(arr1)) ? "equal" : "not equal") << endl;
  }
  return 0;
}