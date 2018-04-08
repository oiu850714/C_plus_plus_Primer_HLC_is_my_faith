#include <fstream>
#include <iostream>
#include <string>

const std::string nonscender{"acemnorsuvwxz"};

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
    exit(1);
  }
  // assume user give correct input file name
  std::ifstream file(argv[1]);
  std::string longest_str, current_str;
  while (file >> current_str) {
    if (current_str.find_first_not_of(nonscender) == std::string::npos
        /* find a word that contains no descender and ascender */
        && current_str.size() > longest_str.size()
        /* and this string is longer than current longest string*/
        ) {
      longest_str = current_str;
    }
  }
  std::cout << longest_str << std::endl;
}