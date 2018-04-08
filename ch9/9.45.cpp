#include <string>

std::string &full_name(std::string &name, const std::string &prefix,
                       const std::string &suffix) {
  name.insert(name.begin(), prefix.begin(), prefix.end());
  name.append(suffix);
  return name;
}
using std::string;
#include <iostream>
int main() {
  string name("Wang");
  std::cout << full_name(name, "Mr.", ", III") << std::endl;
  return 0;
}