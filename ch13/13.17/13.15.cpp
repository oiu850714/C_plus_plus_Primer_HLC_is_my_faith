#include <iostream>
using std::cout;
using std::endl;

class numbered {
public:
  numbered() : mysn(unique++) {}
  numbered(const numbered &num) : mysn(unique++) {}
  int mysn;
  static int unique;
};

int numbered::unique = 0;
// static data member 一定要在 class definition 外面定義

void f(numbered s) { cout << s.mysn << endl; }

int main() {
  numbered a, b = a, c = b;
  f(a);
  f(b);
  f(c);
}
