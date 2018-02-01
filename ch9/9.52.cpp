// 參考: https://github.com/Mooophy/Cpp-Primer/blob/master/ch09/ex9_52.cpp
#include <iostream>
#include <stack>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::stack;

int main() {
  string expression{"change string in (parentheses)"};
  cout << "Original string: " << expression << endl;
  bool bSeen = false;
  stack<char> stackk;
  for (const auto &s : expression) {
    if (s == '(') {
      bSeen = true;
      continue;
    } else if (s == ')')
      bSeen = false;

    if (bSeen)
      stackk.push(s); // 只會在 stack 裡面 push () 內的字串
  }

  string repstr;
  while (!stackk.empty()) {
    repstr += stackk.top();
    stackk.pop();
  } // repstr 會存著 () 的字串，但是順序倒過來

  expression.replace(expression.find("(") + 1, repstr.size(), repstr);

  cout << "Replaced string: " << expression << endl;

  return 0;
}