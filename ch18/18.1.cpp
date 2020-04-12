#include <stdexcept>

int main() {
  //(a)
  std::range_error r("error");
  throw r;
  // expression type is std::range_error

  //(b)
  std::exception *p = &r;
  throw * p;
  // expression type is std::exception

  // If expression is throw p; that will be UB because local object will be
  // destroyed when the corresponding block is unwinded
}