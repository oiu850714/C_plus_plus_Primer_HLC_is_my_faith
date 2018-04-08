// Rewrite the previous function using an index and replace.
#include <string>

void func(std::string &s, const std::string &oldVal,
          const std::string &newVal) {
  for (size_t i = 0; i != s.size();) {
    if (oldVal == s.substr(i, oldVal.size())) { // find oldVal in s
      s.replace(i, oldVal.size(), newVal);

      i += newVal.size();
      // advance index "after" the newVal being inserted
    } else {
      ++i;
    }
  }
}
#include <iostream>
using std::string;
using std::cout;
using std::endl;

int main() {
  string s{"Write a function that takes three strings, s, oldVal,and newVal. "
           "Using iterators, and the insert and erase functions replace all "
           "instances of oldVal that appear in s by newVal. Test your function "
           "by using it to replace common abbreviations, such as \"tho\" by "
           "\"though\" and \"thru\" by \"through\"."};
  func(s, "tho", "though");
  func(s, "thru", "through");
  cout << s << endl;

  return 0;
}