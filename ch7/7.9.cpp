#include <iostream>
#include <string>

struct Person {
  std::string name;
  std::string address;

  auto get_name() const -> const std::string & { return name; }
  auto get_address() const -> const std::string & { return address; }
  // These functions should use const qualifier because they didn't change class
  // member, and const Person object can also use these functions
};

std::ostream &print(std::ostream &os, const Person &person) {
  os << person.name << " " << person.address;
  return os;
}

std::istream &read(std::istream &is, Person &person) {
  is >> person.name >> person.address;
  return is;
}