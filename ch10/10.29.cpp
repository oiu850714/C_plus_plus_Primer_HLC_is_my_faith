#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::ifstream;
using std::vector;
using std::string;
using std::istream_iterator;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

int main(int argc, char **argv) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " file_name" << endl;
    return 1;
  }
  ifstream is;
  is.open(argv[1]);
  if (!is) {
    cerr << "Open file failed" << endl;
    return 1;
  }

  istream_iterator<string> string_iter(is), eof;
  vector<string> vec(string_iter, eof);

  for (auto &str : vec)
    cout << str << " ";
  cout << endl;
}