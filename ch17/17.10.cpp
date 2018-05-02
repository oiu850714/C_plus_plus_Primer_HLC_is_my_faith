#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
using std::bitset;
using std::string;

int main() {
  string str = "0111010010000100000001";
  std::reverse(str.begin(), str.end());
  bitset<32> set1(str);

  bitset<32> set2;
  set2.set(1);
  set2.set(2);
  set2.set(3);
  set2.set(5);
  set2.set(8);
  set2.set(13);
  set2.set(21);

  std::cout << set1 << std::endl;
  std::cout << set2 << std::endl;
}