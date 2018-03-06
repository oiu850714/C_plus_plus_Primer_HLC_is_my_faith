#include "16.24.h"
#include <iostream>
#include <set>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;

template <typename _container>
void print_contents(std::ostream &os, const _container &c) {
  for (auto i = 0; i != c.size(); i++) {
    os << c[i] << " ";
  }
  os << std::endl;
}

int main() {
  vector<int> ivec{7, 5, 3, 3, 9, 6, 7};
  set<string> sset{"This", "is", "set", "of", "string"};
  string str = "hsilu so cute\n";

  // ex 16.24: use ctor template
  Blob<int> iblob(ivec.begin(), ivec.end());
  Blob<string> sblob(sset.begin(), sset.end());
  Blob<char> cblob(str.begin(), str.end());

  print_contents(cout, iblob);
  print_contents(cout, sblob);
  print_contents(cout, cblob);
}