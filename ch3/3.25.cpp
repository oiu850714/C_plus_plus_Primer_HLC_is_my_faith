#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/*
int main() {
  // count the number of grades by clusters often: 0--9, 10--19, . .. 90--99,
  // 100
  vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
  unsigned grade;
  while (cin >> grade) {    // read the grades
    if (grade <= 100)       // handle only valid grades
      ++scores[grade / 10]; // increment the counter for the current cluster
  }
}
*/

int main() {
  // count the number of grades by clusters often: 0--9, 10--19, . .. 90--99,
  // 100
  vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
  unsigned grade;
  while (cin >> grade) { // read the grades
    if (grade <= 100)    // handle only valid grades
      //(*(scores.begin() + grade / 10))++;
      ++*(scores.begin() + grade / 10); // better way
    // increment the counter for the current cluster
  }
  for (auto it = scores.cbegin(); it != scores.cend(); it++)
    cout << *it << " ";
  cout << endl;
  return 0;
}