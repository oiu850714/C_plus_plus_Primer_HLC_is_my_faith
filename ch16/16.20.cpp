#include <iostream>

template <typename _container>
void print_contents(std::ostream &os, const _container &c) {
  for (typename _container::const_iterator it = c.begin(); it != c.end();
       // when you forget that parameter is const reference and you use
       // _container::iterator to declare "it" and compiler bursts utter library
       // code garbages, you will find how cute auto is
       ++it) {
    os << *it << " ";
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