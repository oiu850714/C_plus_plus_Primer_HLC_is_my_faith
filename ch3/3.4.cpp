#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

/*
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  if (s1 == s2)
    cout << "equal" << endl;
  else if (s1 > s2)
    cout << s1 << " > " << s2 << endl;
  else
    cout << s1 << " < " << s2 << endl;
  return 0;
}
*/

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  if (s1.size() == s2.size())
    cout << "same length" << endl;
  else if (s1.size() > s2.size())
    cout << s1 << " longer" << endl;
  else
    cout << s2 << " longer" << endl;
  return 0;
}
