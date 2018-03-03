#include <functional>
#include <map>
#include <string>

using std::map;
using std::string;
using std::function;

int main() {
  map<string, function<int(int, int)>> binops = {
      {"+", [](int i, int j) { return i + j; }}, // function pointer
      {"-", std::minus<int>()},                  // library function object
      {"/", [](int i, int j) { return i / j; }}, // user-defined function object
      {"*", [](int i, int j) { return i * j; }}, // unnamed lambda
      {"%", [](int i, int j) { return i % j; }}}; // named lambda object
}