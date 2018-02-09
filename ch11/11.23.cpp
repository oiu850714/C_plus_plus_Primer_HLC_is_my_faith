#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::vector;
using std::map;
using std::multimap;
using std::string;
using std::istringstream;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::pair;

// assume input format: {last_name first_name}...

using fullname_map = multimap<string, string>;

int main() {
  fullname_map familys;
  string last_name, first_name;
  while (cin >> last_name >> first_name) {
    familys.emplace(last_name, first_name);
  }
  for (const auto &e : familys)
    cout << "full name: " << e.second << " " << e.first << endl;
}