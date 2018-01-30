#include <list>
#include <string>
#include <vector>

using std::vector;
using std::list;
using std::string;

int main() {
  list<const char *> list_c_str{"I", "love", "hsilu"};
  vector<string> vec_str;
  vec_str.assign(list_c_str.begin(), list_c_str.end());
}