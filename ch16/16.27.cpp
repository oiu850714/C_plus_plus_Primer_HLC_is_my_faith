#include <string>
using std::string;

template <typename T> class Stack {};
void f1(Stack<char>); // (a): instantiates Stack<char>
class Exercise {
  Stack<double> &rsd; // (b): instantiates Stack<double>
  Stack<int> si;      // (c): instantiates Stack<int>
};
int main() {
  Stack<char> *sc;                  // (d): instantiation already exists
  f1(*sc);                          // (e): instantiation already exists
  int iObj = sizeof(Stack<string>); // (f): instantiates Stack<strin>
}