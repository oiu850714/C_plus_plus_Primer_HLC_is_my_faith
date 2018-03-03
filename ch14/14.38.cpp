#include <fstream>
#include <iostream>
#include <string>

class CheckStrBound {
public:
  CheckStrBound(size_t _lower, size_t _upper);
  bool operator()(const std::string &);

private:
  size_t lower;
  size_t upper;
};

CheckStrBound::CheckStrBound(size_t _lower, size_t _upper)
    : lower(_lower), upper(_upper) {
  if (lower > upper) { // toy error handling
    std::cerr << "change lower to 0";
    lower = 0;
  }
}

bool CheckStrBound::operator()(const std::string &s) {
  return lower <= s.size() && s.size() <= upper;
}

void report_length(std::istream &is, size_t lower, size_t upper) {
  std::string s;
  CheckStrBound check(lower, upper);
  int count = 0;

  while (is >> s) {
    count += check(s);
  }

  if (lower > upper)
    lower = 0;

  std::cout << count << " words have size " << lower << " through " << upper
            << " inclusive\n";
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " file_name\n";
    return 1;
  }

  std::ifstream is(argv[1]); // assumue file open success
  report_length(is, 5, 10);
}