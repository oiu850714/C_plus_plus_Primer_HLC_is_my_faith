#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {
  const string s = "Keep out!";
  for (auto &c : s) {
    /*...*/
    // it's legal but statements in loop cannot modifiy c
    // because c is constchar&
  }
}
