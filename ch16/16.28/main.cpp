#include "SharedPtr.h"
#include "UniquePtr.h"

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int main() {
  SharedPtr<vector<int>> p(new vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  cout << "(*p)[0]: " << (*p)[0] << endl;
  cout << "size: " << p->size() << endl;

  SharedPtr<vector<int>> p2(p);
  cout << "(*p2)[1]: " << (*p2)[1] << endl;
  cout << "size: " << p2->size() << endl;

  SharedPtr<vector<int>> p3;
  p3 = p2;
  cout << "(*p3)[2]: " << (*p3)[2] << endl;
  cout << "size: " << p3->size() << endl;

  p3 = SharedPtr<vector<int>>(new vector<int>{7, 5, 3, 3, 9, 6, 7});
  cout << "(*p3)[2]: " << (*p3)[2] << endl;
  cout << "size: " << p3->size() << endl;

  p2 = p3;
  cout << "p2.use_count: " << p2.use_count() << endl;
  cout << "p3.use_count: " << p3.use_count() << endl;
}