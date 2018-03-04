template <typename _iter, typename _value>
_iter find(const _iter &begin, const _iter &end, const _value &val) {
  for (_iter it = begin; it != end; it++) {
    if (*it == val)
      return it;
  }
  return end;
}

#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::vector;
using std::list;
using std::string;

int main() {
  vector<int> ivec{9, 4, 8, 7, 5, 5, 6, 6};
  list<string> lstr{"hsilu", "oiu", "j7", "bilyRIP", "reddit"};
  if (find(ivec.begin(), ivec.end(), 10) == ivec.end())
    std::cout << "not found 10 in ivec\n";

  if (find(ivec.begin(), ivec.end(), 7) != ivec.end())
    std::cout << "found 7 in ivec\n";

  if (find(lstr.begin(), lstr.end(), "yyp") == lstr.end())
    std::cout << "not found \"yyp\" in lstr\n";

  if (find(lstr.begin(), lstr.end(), "hsilu") != lstr.end())
    std::cout << "found \"hsilu\" in lstr\n";
}