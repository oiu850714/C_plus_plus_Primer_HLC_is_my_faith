#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::make_shared;
using std::string;

int main() {
  unique_ptr<int> ptr(new int);
  unique_ptr<int> ptr2(ptr);
  unique_ptr<int> ptr3;
  ptr3 = ptr;
  // compiler prints something like "call to deleted constructor of
  // unique_ptr<int>"
}