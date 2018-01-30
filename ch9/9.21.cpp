// Explain how the loop from page 345 that used the return frominsert to add
// elements to a list would work if we inserted into a vector instead.
// SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch09#exercise-921
// SEE:
// https://github.com/huangmingchuan/Cpp_Primer_Answers/tree/master/ch09#%E7%BB%83%E4%B9%A0921

#include <array>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::array;
using std::list;
using std::string;
using std::vector;

int main() {
  vector<string> lst;
  string word;
  auto iter = lst.begin();
  while (cin >> word) {
    iter = lst.insert(iter, word); // same as calling push_front
  }

  for (auto &e : lst)
    cout << e << " ";
  cout << endl;
}

// 注意，在 vector 的 case 裡，更新 iterator 是必要的，因為一旦更改 vector
// size，iterator 就會失效