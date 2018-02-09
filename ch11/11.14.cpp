#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::vector;
using std::map;
using std::string;
using std::istringstream;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::pair;

// assume input format: {last_name {children_name birthday}...}...

using Family_type = map<string, vector<pair<string, string>>>;

void add_family(Family_type &familys, string &whole_family) {
  string last_name, children_name, birthday;

  istringstream stream(whole_family);
  stream >> last_name;
  while (stream >> children_name >> birthday) {
    familys[last_name].push_back({children_name, birthday});
  }
}

void read_familys(Family_type &familys) {
  string whole_family;
  while (getline(cin, whole_family)) {
    add_family(familys, whole_family);
  }
}

void print_familys(Family_type &familys) {
  for (const auto &family : familys) {
    std::cout << "last name: " << family.first << "; children: ";
    for (const auto &child_info : family.second) {
      std::cout << child_info.first << ", birthday: " << child_info.second
                << "; ";
    }
    cout << endl;
  }
}
int main() {
  Family_type familys;
  read_familys(familys);
  print_familys(familys);
}