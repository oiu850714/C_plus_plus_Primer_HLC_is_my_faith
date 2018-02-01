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

void process(std::shared_ptr<int> ptr) {
  std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

int main() {
  auto sp = make_shared<int>();
  auto p = sp.get();
  delete p;
  // after deleting p, any operation on sp is undefined
}