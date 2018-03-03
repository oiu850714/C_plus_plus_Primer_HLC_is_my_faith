#include <iostream>
#include <string>
class PrintString {
public:
  std::string operator()(std::istream &is) {
    std::string line;
    if (std::getline(is, line))
      return line;
    else
      return std::string();
  }
};