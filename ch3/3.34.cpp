#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

int main() {
  int arr[100];
  int *p1 = arr, *p2 = arr + 100;
  p1 += (p2 - p1);
  // p1 = p1 + (p2 - p1);
  // -> p1 == p2
  // any valid value p1 and p2 make this code legal
}