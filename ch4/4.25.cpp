#include <iostream>
using std::cout;
using std::endl;
int main() {
  int result = ~'q' << 6;
  // 'q's bit pattern: 01110001
  // first, promote: 00000000000000000000000001110001
  // ~'q':           11111111111111111111111110001110
  // ~'q' << 6:      11111111111111111110001110000000
  int(0b11111111111111111110001110000000);
  cout << "result: " << result << endl;
  // BUT ACCORDING TO SOME ANSWER, ITS UNDEFINED
  // https://stackoverflow.com/questions/28141871/bitwise-operators-and-signed-types
  // https://github.com/Mooophy/Cpp-Primer/issues/567
}
