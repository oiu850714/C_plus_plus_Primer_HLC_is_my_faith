#include <iostream>
#include <map>

int main() {
  std::map<int, int> m{{1, 2}, {2, 4}, {3, 6}};
  auto it = m.begin();
  it->second = 87;
  for (const auto &e : m)
    std::cout << e.first << " " << e.second << std::endl;
}