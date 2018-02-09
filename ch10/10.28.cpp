#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

using std::vector;
using std::inserter;
using std::back_inserter;
using std::front_inserter;
using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::deque;

void println(const vector<int> &vec) {
  for (auto i : vec)
    cout << i << " ";
  cout << endl;
}

void println(const deque<int> &deq) {
  for (auto i : deq)
    cout << i << " ";
  cout << endl;
}

int main() {
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  deque<int> deq1, deq2, deq3;
  copy(vec.begin(), vec.end(), inserter<deque<int>>(deq1, deq1.begin()));
  copy(vec.begin(), vec.end(), front_inserter<deque<int>>(deq2));
  copy(vec.begin(), vec.end(), back_inserter<deque<int>>(deq3));

  println(vec);
  println(deq1);
  println(deq2);
  println(deq3);
}