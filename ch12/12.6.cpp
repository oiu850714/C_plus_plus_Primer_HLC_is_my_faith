#include <iostream>
#include <new>
#include <vector>

using std::vector;
using std::nothrow;
using std::bad_alloc;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

auto vector_int_factory() { return new vector<int>; }
void read_elements_to_vector(vector<int> *&ptr) {
  if (!ptr) {
    cerr << "pointer points to NULL!" << endl;
    exit(1);
  }
  int i = 0;
  while (cin >> i) {
    ptr->push_back(i);
  }
}
void print_vector_elements(vector<int> *&ptr) {
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