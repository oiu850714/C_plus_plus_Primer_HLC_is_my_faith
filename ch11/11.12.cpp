#include <iostream>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::vector;
using vec_pair_string_int = vector<pair<string, int>>;

int main() {
  vec_pair_string_int vec;
  for (pair<string, int> p; cin >> p.first >> p.second;) {
    vec.push_back(p);
  }
  for (const auto &p : vec)
    cout << p.first << " " << p.second << endl;
}