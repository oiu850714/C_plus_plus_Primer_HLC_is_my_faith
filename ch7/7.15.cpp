#include <iostream>
#include <string>

struct Person;
std::ostream &print(std::ostream &os, const Person &person);
std::istream &read(std::istream &is, Person &person);

struct Person {
  std::string name;
  std::string address;

  auto get_name() const -> const std::string & { return name; }
  auto get_address() const -> const std::string & { return address; }
  // These functions should use const qualifier because they didn't change class
  // member, and const Person object can also use these functions

  Person() = default;
  Person(const std::string &initial_name, const std::string &initial_address)
      : name(initial_name), address(initial_address) {}
  Person(std::istream &is) { read(is, *this); }
};

std::ostream &print(std::ostream &os, const Person &person) {
  os << person.name << " " << person.address;
  return os;
}

std::istream &read(std::istream &is, Person &person) {
  is >> person.name >> person.address;
  return is;
}