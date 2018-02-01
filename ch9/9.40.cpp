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

// 256: 256*1.5 = 384, < 1024, capacity doesn't change
// 512: 512*1.5 = 768, < 1024, capacity doesn't change
// 1000: 1000*1.5 = 1500, > 1024, capacity >= 1500
// 1048: 1048*1.5 = 1572, > 1024, capacity >= 1572