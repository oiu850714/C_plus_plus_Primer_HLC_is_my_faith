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