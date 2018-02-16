#include <iostream>
#include <memory>
#include <string>

using std::allocator;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
  int n = 0;
  cin >> n;
  allocator<string> alloc;
  auto p = alloc.allocate(n);
  auto q = p;
  string s;
  while (q != p + n && cin >> s) {
    alloc.construct(q++, s);
  }
  const size_t size = q - p;
  for (auto i = 0; i < size; i++) {
    cout << p[i] << " ";
  }
  cout << endl;

  while (q != p) {
    alloc.destroy(--q);
  }
  alloc.deallocate(p, n);
}