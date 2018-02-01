#include <iostream>
#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::make_shared;

int main() {
  int *q = new int(42), *r = new int(100);
  r = q; // int object that has value 100 is leaked
  auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
  r2 = q2; // r2's previously pointed object is automatically deleted
}