#include <iostream>

int main() {
  // (a)
  std::cin >> int input_value; // syntax error
  // (b)
  int i = {3.14}; // It is error because it use list initialization, and
                  // initializer may lose information.
  // (c)
  double salary = wage = 9999.99; // it is not an syntax error if wage is
                                  // defined and has build-in types
  // (d)
  int i = 3.14; // correct but lose information
}

/*
int main() {
  double a = 100.0;
  double salary = a = 9999.99;
  std::cout << a << " " << salary << std::endl;
  return 0;
}
code above just check syntex in problem (c) is correct
*/