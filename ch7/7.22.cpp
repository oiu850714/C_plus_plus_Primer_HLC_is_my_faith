#include <iostream>
#include <string>

class Person;
std::ostream &print(std::ostream &os, const Person &person);
std::istream &read(std::istream &is, Person &person);

class Person {
  // let two nonmember function that are part of class' interface access class'
  // private members
  friend std::ostream &print(std::ostream &os, const Person &person);
  friend std::istream &read(std::istream &is, Person &person);

private:
  std::string name;
  std::string address;
  // above two string members cannot be accessed directly, they should be
  // declared private
public:
  // functions below constitute class Person's interface, they should be
  // declared public
  auto get_name() const -> const std::string & { return name; }
  auto get_address() const -> const std::string & { return address; }
  // These functions should use const qualifier because they didn't change class
  // member, and const Person object can also use these functions
  void set_name(const std::string &sname) { name = sname; }
  void set_address(const std::string &saddress) { address = saddress; }

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