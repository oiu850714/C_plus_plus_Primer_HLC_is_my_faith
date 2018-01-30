#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::deque;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::forward_list;

// ex 9.28
void func(forward_list<string> &flst, string &str1, string &str2) {
  auto prev = flst.before_begin();
  auto curr = flst.begin();
  bool flag = false;

  while (curr != flst.end()) {
    if (*curr == str1) {
      curr = flst.insert_after(curr, str2);
      // insert_after return iterator to the last insert element
      prev = curr++;
      flag = true;
    } else {
      ++curr;
      ++prev;
    }
  }
  if (!flag)
    flst.insert_after(prev, str2);
}

int main() {
  forward_list<string> flst{"hsilu", "super", "cute", "but",  "J7",
                            "sucks", "cute",  "cure", "cute", "cute"};
  for (const auto &e : flst)
    cout << e << " ";
  cout << endl;

  string s1{"cute"}, s2{"LOVE"};
  func(flst, s1, s2);

  for (const auto &e : flst)
    cout << e << " ";
  cout << endl;

  string s3{"HENTAI"}, s4{"flashing"};
  func(flst, s3, s4);

  for (const auto &e : flst)
    cout << e << " ";
  cout << endl;
}