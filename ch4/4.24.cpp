#include <string>
using std::string;
int main() {
  int grade = 87;
  string finalgrade;
  finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";

  // if left associative, it will be like this:
  finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
}
// and it will not compile because the first ?: 's two expressions, that is,
// "high pass" and (grade < 60), have different type that cannot be converted to
// same type (string and bool)

// note: on https://github.com/Mooophy/Cpp-Primer/tree/master/ch04#exercise-424
// there is an issue for this answer:
// https://github.com/Mooophy/Cpp-Primer/issues/517