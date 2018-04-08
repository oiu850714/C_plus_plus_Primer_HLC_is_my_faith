#include <iostream>
#include <string>

const std::string numbers{"0123456789"};
const std::string alphabet{
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

// Both versions assume strings have only alphabet and numeric characters

void find_position_of_num_and_alpha_ver1(const std::string &s) {
  std::string::size_type pos = 0;

  std::cout << "position of numbers:";
  while ((pos = s.find_first_of(numbers, pos)) != std::string::npos) {
    std::cout << " " << pos++; // don't forget to increment pos
  }
  std::cout << std::endl;

  pos = 0;
  std::cout << "position of alphabet:";
  while ((pos = s.find_first_of(alphabet, pos)) != std::string::npos) {
    std::cout << " " << pos++; // don't forget to increment pos
  }
  std::cout << std::endl;
}
void find_position_of_num_and_alpha_ver2(const std::string &s) {
  std::string::size_type pos = 0;

  std::cout << "position of numbers:";
  while ((pos = s.find_first_not_of(alphabet, pos)) != std::string::npos) {
    std::cout << " " << pos++; // don't forget to increment pos
  }
  std::cout << std::endl;

  pos = 0;
  std::cout << "position of alphabet:";
  while ((pos = s.find_first_not_of(numbers, pos)) != std::string::npos) {
    std::cout << " " << pos++; // don't forget to increment pos
  }
  std::cout << std::endl;
}

int main() {
  std::string s{"01234567qqQQ10101jdjAAA"};
  find_position_of_num_and_alpha_ver1(s);
  find_position_of_num_and_alpha_ver2(s);
}