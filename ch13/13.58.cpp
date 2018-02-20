#include <iostream>
using std::cout;

class Foo {
public:
  Foo sorted() const & {
    cout << "lvalue sorted\n";
    /*
        // ex 13.56
        Foo ret(*this);
        return ret.sorted();
    */

    // ex 13.57
    return Foo().sorted();
  }
  Foo sorted() && {
    cout << "rvalue sorted\n";
    return *this;
  }
};

int main() {
  Foo f1;
  cout << "use lvalue to call sorted:\n";
  f1.sorted();
  cout << "use rvalue to call sorted:\n";
  Foo().sorted();
  std::move(f1);
}