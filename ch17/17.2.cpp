#include <string>
#include <tuple>
#include <utility>
#include <vector>
using std::pair;
using std::string;
using std::vector;
using std::tuple;
using std::make_tuple;
int main() {
  auto t = make_tuple(string(), vector<string>(), pair<string, int>());
}