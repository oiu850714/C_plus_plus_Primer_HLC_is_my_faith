#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

using std::sort;
using std::find_if;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int main(int argc, char **argv) {
  if (argc < 4) {
    cout << "Usage: " << argv[0] << " input_file output_file1 output_file2\n";
    return 1;
  }

  // assume open file will success
  ifstream is(argv[1]);
  ofstream os_odd(argv[2], std::ofstream::out);
  ofstream os_even(argv[3], std::ofstream::out);

  istream_iterator<int> is_iter(is), eof;
  ostream_iterator<int> os_odd_iter(os_odd, " "), os_even_iter(os_even, "\n");

  while (is_iter != eof) {
    if (*is_iter & 0x1) {
      os_odd_iter = *is_iter++;
    } else {
      os_even_iter = *is_iter++;
    }
  }
}
// SEE:
// https://github.com/huangmingchuan/Cpp_Primer_Answers/blob/master/ch10/exercise10_33.cpp
// it uses for_each, and uses conditional expression in lhs of assignment!!
