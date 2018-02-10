#include <map>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::map;

int main() {
  map<string, vector<int>> m{{"hsilu", {0, 2, 1, 6}}, {"J7", {0, 7, 1, 4}}};
  map<string, vector<int>>::iterator it = m.find("hsilu");
}