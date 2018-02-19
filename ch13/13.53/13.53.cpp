#include "13.53_copy_and_swap.h"
//#include "13.53_independent_assign.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

#include <ctime>

int main() {
  string s1 = "q";
  HasPtr p1(s1);
  const int len = 3000000;
  vector<HasPtr> vec(len, p1);

  auto begin = clock();
  HasPtr p2;
  for (int i = 0; i < len; i++) {
    p2 = std::move(vec[i]);
  }
  auto end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << elapsed_secs << endl;
}