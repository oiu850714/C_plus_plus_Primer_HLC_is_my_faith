#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  vector<string> svec;
  svec.reserve(1024); // change capacity to at least 1024
  string word;
  while (cin >> word)
    svec.push_back(word); // depending on #word, svec may reallocate
  svec.resize(svec.size() + svec.size() / 2);
  // add svec.size()/2 default initailized string, that is, empty string, to
  // svec; if svec.size() + svec.size()/2 > svec.capacity() then reallocate
}