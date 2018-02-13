// SEE: https://github.com/Mooophy/Cpp-Primer/blob/master/ch13/ex13_19.h
// copying employees is not make sense
#include <string>

class Employee {
private:
  std::string name;
  int id;

  static int unique_id;

public:
  Employee() : id(unique_id++) {}
  Employee(const std::string &s) : name(s), id(unique_id++) {}
  Employee(const Employee &employee) = delete;
  Employee &operator=(const Employee &employee) = delete;
};

int Employee::unique_id = 0;