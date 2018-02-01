#include <memory>

using std::shared_ptr;
using std::unique_ptr;

int main() {
  int ix = 1024, *pi = &ix, *pi2 = new int(2048);
  typedef unique_ptr<int> IntP;
  //(a)
  IntP p0(ix); // compile error, argument cannot be int
  //(b)
  IntP p1(pi); // object that is not in dynamic memory, undefined
  //(c)
  IntP p2(pi2); // OK
  //(d)
  IntP p3(&ix); // same as p1, &ix is not address in dynamic memory
  //(e)
  IntP p4(new int(2048)); // OK
  //(f)
  IntP p5(p2.get()); // that makes two unique_ptr point to same object!
}