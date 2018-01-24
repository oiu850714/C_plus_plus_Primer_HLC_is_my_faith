#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::isupper;
using std::scanf;
using std::strcmp;
using std::string;
using std::strncat;
using std::strncpy;
using std::vector;

int main(int argc, char **argv) { // #argc = 1(program name) + #options
  for (int i = 1; i < argc; i++)
    // for (int i = 1; i <= argc; i++)
    cout << argv[i] << " ";
  // std::ios_base::sync_with_stdio(false);
  cout << endl;
  // std::cerr << (cout.failbit ? "cout crash" : "yeee") << std::endl;
  // std::cerr << (cout.badbit ? "cout crash" : "yeee") << std::endl;
  // std::cerr << (cout.eofbit ? "cout crash" : "yeee") << std::endl;
}