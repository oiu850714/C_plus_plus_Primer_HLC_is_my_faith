#include <list>
#include <vector>

using std::vector;
using std::list;

int main() {
  list<int> list_int{1, 2, 3, 4, 5};
  vector<int> vec_int(94, 87);

  vector<double> vec_1(list_int.begin(), list_int.end());
  // container needn't be the same, element convertible
  vector<double> vec_2(vec_int.begin(), vec_int.end());
  // container be the same, element convertible
}