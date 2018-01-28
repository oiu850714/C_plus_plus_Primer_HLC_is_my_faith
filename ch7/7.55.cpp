#include <string>
using std::string;

struct Data {
  int ival;
  string s;
};
// no, string is not literal type
// SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch07#exercise-755
// you can use code in the link to verify that Data is not literal type