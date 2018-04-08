// Write a function that takes three strings, s, oldVal,and newVal. Using
// iterators, and the insert and erase functions replace all instances of oldVal
// that appear in s by newVal. Test your function by using it to replace common
// abbreviations, such as "tho" by "though" and "thru" by "through".
#include <string>

void func(std::string &s, const std::string &oldVal,
          const std::string &newVal) {
  for (auto it = s.begin(); it != s.end();) {
    if (oldVal == std::string(it, it + oldVal.size())) { // find oldVal in s
      // s.replace(it, it + oldVal.size(), newVal);
      it = s.erase(it, it + oldVal.size());
      it = s.insert(it, newVal.begin(), newVal.end());
      // must need to assign return iterator to it, because these member
      // function that change string content will invalid iterator pointing to
      // the string elements

      it += newVal.size();
      // advance iterator "after" the newVal being inserted
    } else {
      ++it;
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