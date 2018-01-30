#include <array>
#include <iostream>
#include <string>
#include <vector>

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/*
int main() {
  vector<int> iv{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
  int some_val = 9;
  cin >> some_val;
  while (iter != mid)
    if (*iter == some_val)
      iv.insert(iter, 2 * some_val);
  // 1. mid and iter will be invalid after insert
  // 2. mid - iter always != 0, so loop will never end
}
*/

int main() {
  vector<int> iv{2, 2, 3, 2, 4, 2, 6, 2, 2, 2, 2};
  vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
  int some_val = 0;
  cin >> some_val;
  while (iter != iv.end()) {
    if (*iter == some_val) {
      ++(iter = iv.insert(iter, 2 * some_val)); // need to assign iter to new
      // iterator to keep it valid
    }
    mid = iv.begin() + iv.size() / 2; // same reason for mid
    if (iter == mid)
      break; // 因為我們在 iter 前面插了一個 element，然後將 iter
             // 更新到這個 element 的下一個位置，所以 iter 有可能已經跟 mid
             // 指向同一個位置，這時候就必須判斷 iter == mid
             // 然後跳出迴圈；
             // 否則如果把 iter != mid 放在 while
             // condition 判斷的話，下一行的 ++iter 會讓 iter 跑到 mid
             // 之後，這樣 iter 就再也不可能 == mid 了；
             // 更慘的是如果把 iter != mid 放在 while condition，然後 while
             // condition 又沒有判斷 iter != iv.end()，這樣 iter 就會超過
             // iv.end()，然後 segmentation fault
    ++iter;
  }
  for (auto e : iv)
    cout << e << " ";
  cout << endl;
}