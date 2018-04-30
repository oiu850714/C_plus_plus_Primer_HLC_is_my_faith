#include <bitset>
#include <iostream>
#include <string>

using std::bitset;
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
  //(a)
  bitset<64> bitvec(32);
  // 00..58 0's..0100000
  //(b)
  bitset<32> bv1(1010101);
  // 0000000000001110110100110110101
  //(c)
  string bstr;
  cin >> bstr;
  bitset<8> bv2(bstr);
  // 如果你的 string 長度大於 8，則 bitset 只會拿 index 0~7 的字元來初始化
  // bitset，並且 index 7 的字元是 LSB 如果小於 8，則就跟 Primer p.725
  // 的規則一樣
  cout << bv2 << endl;
}