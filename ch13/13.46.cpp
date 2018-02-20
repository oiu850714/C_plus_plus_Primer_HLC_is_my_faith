#include <vector>
using std::vector;

int f();
vector<int> vi(100);
// int? r1 = f();
// rvalue reference

// int? r2 = vi[0];
// lvalue reference

// int? r3 = r1;
// lvalue reference, when using r1 as variable it will be treated as lvalue

// int? r4 = vi[0] * f();
// rvalue reference