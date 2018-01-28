#include <string>
#include <vector>

using std::string;
using std::vector;

int main() {
  vector<int> vec = 10;
  // It seems like int 10 can convert to vector<int>, it's really strange
  // and every function that has vector<int> parameter can receive an int
  // void getSize(const vector<int>&);
  // getSize(87);
  // it will convert 87 implicitly to vector<int> with 87 default ints
  // really confusing

  string str = "hsilu";
  // I think everyone can read this code with no stress
}

// SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch07#exercise-751