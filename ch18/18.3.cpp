// you can use a class to wrap new and delete, please look "RAII" idiom
// or you can use smart pointer

#include <fstream>
#include <memory>
#include <vector>

using std::vector;
using std::ifstream;
using std::unique_ptr;

void exercise(int *b, int *e) {
  vector<int> v(b, e);
  unique_ptr<int[]> p(new int[v.size()]);
  ifstream in("ints");
  // exception occurs here

  // the object to which p allocates will be leaked
}