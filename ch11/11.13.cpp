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
  //   vec_pair_string_int vec;
  //   for (pair<string, int> p; cin >> p.first >> p.second;) {
  //     vec.push_back(p);
  //   }
  vec_pair_string_int vec;
  int i = 0;
  string s;
  while (cin >> s >> i) {
    vec.push_back(std::make_pair(s, i));
    //   vec.push_back({s, i});
    //   vec.push_back(pair<string, int>(s, i));
    // I think the code I write in 11.12.cpp is easiest to write and understand
    // lol
  }
  for (const auto &p : vec)
    cout << p.first << " " << p.second << endl;
}