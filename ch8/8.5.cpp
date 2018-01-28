#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::endl;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::getline;

int main(int argc, char **argv) {
  if (argc < 2) {
    cout << "please give file name" << endl;
    return 1;
  }
  ifstream in(argv[1]);
  if (!in) {
    cout << "open file failed" << endl;
    return 1;
  }
  vector<string> file_contents;
  string line;
  while (in >> line) {
    file_contents.push_back(line);
  }

  for (const auto &line : file_contents)
    cout << line << " ";
}