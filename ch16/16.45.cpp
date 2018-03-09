#include <vector>
using std::vector;

template <typename T> void g(T &&val) { vector<T> v; }

int main() {
  g(42); // pass const rvalue, T is int and val is int&&; i.e.,
  // g<int>(int &&val);

  // By the way, see:
  // https://stackoverflow.com/questions/33085796/what-happens-when-you-assign-a-literal-constant-to-an-rvalue-reference
  // it explains that assigning a const literal to rvalue reference will create
  // a temporary object

  int i;
  // g(i); // will burst errors, because container elements cannot be reference
  // type
}
