#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using std::accumulate;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::equal;

// // this is an example on Primer p.379, I think + on const char* and string is
// // defined
// int main() {
//   vector<string> vec{"sss", "www", "lll"};
//   cout << accumulate(vec.cbegin(), vec.cend(), "") << endl;
//   // it looks like this
//   // char* result = "";
//   // for(auto e : vec)
//   //   resutl = result + e;
//   //                   ^ this + is defined, we can add const char* with
//   string,
//   //                   and the type of result is string
//   //          ^ this = is not defined, cannot assign string to const char*
//   //          or even char*
// }

int main() {
  vector<const char *> vec1{"sss", "www", "lll"};
  vector<const char *> vec2{"sss", "www", "lll"};
  cout << equal(vec1.begin(), vec1.end(), vec2.begin()) << endl;
  // equal will compare two const char*, which are addresses rather than literal
  // SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch10#exercise-105
}