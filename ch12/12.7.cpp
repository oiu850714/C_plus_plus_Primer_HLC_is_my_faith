#include <iostream>
#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::make_shared;

auto vector_int_factory() {
  auto ptr{make_shared<vector<int>>()}; // make_shared is function template, the
                                        // parentheses must not omitted
  return ptr;
}
void read_elements_to_vector(shared_ptr<vector<int>> ptr) {
  if (!ptr) {
    cerr << "pointer points to NULL!" << endl;
    exit(1);
  }
  int i = 0;
  while (cin >> i) {
    ptr->push_back(i);
  }
}
void print_vector_elements(shared_ptr<vector<int>> ptr) {
  for (auto i : *ptr) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  auto vector_int_ptr = vector_int_factory();
  read_elements_to_vector(vector_int_ptr);
  print_vector_elements(vector_int_ptr);
}