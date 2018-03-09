// You can call max by providing explicit template argument:
#include <algorithm>

int main() {
  std::max<int>(1, 8.7); // although compiler will burst narrow down warning
}