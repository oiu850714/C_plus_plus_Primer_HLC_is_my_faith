#include <iostream>

template <typename _container>
void print_contents(std::ostream &os, const _container &c) {
  for (typename _container::size_type i = 0; i < c.size(); ++i) {
    os << c[i] << " ";
  }
  os << std::endl;
}

#include <string>
#include <vector>
int main() {
  std::vector<int> ivec{9, 4, 8, 7, 9, 4, 5};
  std::string str = "hsilu so cute";
  std::vector<std::string> svec{"This", "is", "a", "vector", "of", "string"};

  print_contents(std::cout, ivec);
  print_contents(std::cout, str);
  print_contents(std::cout, svec);
}