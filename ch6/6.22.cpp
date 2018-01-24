#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::isupper;
using std::scanf;
using std::strcmp;
using std::string;
using std::strncat;
using std::strncpy;
using std::vector;
using std::tolower;

void swap_ptr_to_int(int **p1, int **p2) {
  int *temp_ptr = *p1;
  *p1 = *p2;
  *p2 = temp_ptr;
}
// C version is shitty, below is C++ reference version

void swap_ptr_to_int(int *&r1, int *&r2) {
  int *temp_ptr = r1;
  r1 = r2;
  r2 = temp_ptr;
}

int main() {
  int i = 94, j = 87;
  int *ptr_i = &i, *ptr_j = &j;
  swap_ptr_to_int(&ptr_i, &ptr_j);
  cout << "ptr_i points: " << *ptr_i << " ptr_j points: " << *ptr_j << endl;
  swap_ptr_to_int(ptr_i, ptr_j);
  cout << "ptr_i points: " << *ptr_i << " ptr_j points: " << *ptr_j << endl;
}