#include "16.12.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Blob<int> b{0, 1, 2, 3, 4, 5, 8, 7, 6, 9};
  cout << "b.back(): " << b.back() << endl;
  cout << "b.front(): " << b.front() << endl;
  b.push_back(10);
  cout << "after push_back, b.back(): " << b.back() << endl;
  b.pop_back();
  cout << "after pop_back, b.back(): " << b.back() << endl;
  cout << "b[0]: " << b[0] << endl;

  Blob<int> const_b{0, 1, 2, 3, 4, 5, 8, 7, 6, 9};
  cout << "const_b.back(): " << const_b.back() << endl;
  cout << "const_b.front(): " << const_b.front() << endl;

  cout << "b == const_b: " << operator==(b, const_b) << endl;

  BlobPtr<int> bptr(b, 5);
  cout << "*bptr: " << *bptr << endl;
  ++bptr;
  cout << "after ++bptr, *bptr: " << *bptr << endl;
}