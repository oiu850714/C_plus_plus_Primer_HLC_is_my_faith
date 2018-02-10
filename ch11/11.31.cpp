#include <iostream>
#include <map>
#include <string>

using std::multimap;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
  multimap<string, string> name_to_works{{"Hsilu", "teacher"},
                                         {"Hsilu", "Tenshi"},
                                         {"J7", "neet"},
                                         {"J7", "student"}};
  auto it = name_to_works.find("Hsilu");
  if (it != name_to_works.end()) {
    name_to_works.erase(it);
  }
  for (const auto &e : name_to_works) {
    cout << e.first << " " << e.second << endl;
  }
}