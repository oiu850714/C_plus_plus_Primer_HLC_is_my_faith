#include <iostream>
using std::cin;
using std::cout;

#define PREDEFINED_LEN 9487

int main() {
  char *p = new char[PREDEFINED_LEN];
  cin.get(p, PREDEFINED_LEN, EOF);
  cout << p;
  // if input > predefined length, it will be ignored and not put on to dynamic
  // memory
  // or SEE: https://github.com/Mooophy/Cpp-Primer/blob/master/ch12/ex12_24.cpp
  // you can ask for the given length
}