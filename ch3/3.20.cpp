#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  vector<int> ivec;
  int temp = 0;
  while (cin >> temp) {
    ivec.push_back(temp);
  }

  if (ivec.size() == 0) {
    cout << "input at least one integer" << endl;
    return -1;
  }

  for (int i = 0; i < ivec.size() - 1; i++) {
    cout << ivec[i] + ivec[i + 1];
    cout << ((i != ivec.size() - 2) ? " " : "\n");
  }

  if (ivec.size() % 2 == 1) {
    for (int i = 0; i < ivec.size() / 2 + 1; i++) {
      if (i == ivec.size() / 2)
        cout << ivec[i];
      else
        cout << ivec[i] + ivec[ivec.size() - i - 1];
      cout << (i != ivec.size() / 2 ? " " : "\n");
    }
  } else {
    for (int i = 0; i < ivec.size() / 2; i++) {
      cout << ivec[i] + ivec[ivec.size() - i - 1];
      cout << (i != ivec.size() / 2 - 1 ? " " : "\n");
    }
  }
  return 0;
}