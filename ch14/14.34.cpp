class funcobj {
public:
  int operator()(bool cond, int i1, int i2) { return cond ? i1 : i2; }
};

#include <iostream>
#include <vector>
using std::vector;
int main() {
  vector<int> v;
  std::cout << funcobj()(v.empty(), 94, 87) << std::endl;
  v.push_back(87);
  std::cout << funcobj()(v.empty(), 94, 87) << std::endl;
}