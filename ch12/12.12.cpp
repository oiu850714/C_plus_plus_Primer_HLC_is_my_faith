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
  auto p = new int();
  auto sp = make_shared<int>();
  //(a)
  process(sp); // legal
  //(b)
  process(new int()); // error: must use explicit conversion from raw pointer to
                      // shared_ptr
  //(c)
  process(p); // error: same reason as (b)
  //(d)
  process(shared_ptr<int>(p)); // runtime error: p is dangling pointer
}