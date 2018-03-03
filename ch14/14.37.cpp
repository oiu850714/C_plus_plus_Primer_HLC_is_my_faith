class is_Equal {
public:
  is_Equal(int _i) : i(_i){};
  bool operator()(int num) { return i == num; }

private:
  int i;
};

#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;
int main() {
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 4, 3, 3, 3, 10, 3};
  std::replace_if(vec.begin(), vec.end(), is_Equal(3), 87);

  std::for_each(vec.begin(), vec.end(), [](int i) { std::cout << i << " "; });
  std::cout << std::endl;
}
