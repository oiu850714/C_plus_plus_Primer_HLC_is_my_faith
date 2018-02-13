#include <string>

class Employee {
private:
  std::string name;
  int id;

  static int unique_id;

public:
  Employee() : id(unique_id++) {}
  Employee(const std::string &s) : name(s), id(unique_id++) {}
};

int Employee::unique_id = 0;