#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
  vector<int> vec(25, 87);
  vec.resize(100); // 塞入 75 個 0
  for (auto e : vec)
    cout << e << " ";
  cout << endl;

  vec.resize(10); // 刪除後面 90 個元素，剩下 10 個 25
  for (auto e : vec)
    cout << e << " ";
  cout << endl;
}