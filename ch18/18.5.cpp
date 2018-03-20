#include <cstdlib>
#include <iostream>
#include <stdexcept>
int main() {
  try {
    // use ofthe C++ standard library
  } catch (std::exception &e) {
    // base class is std::exception, so using std::exception parameter call
    // catch all types of exception in the hierarchy
    std::cout << e.what() << std::endl;
    abort();
  }
}