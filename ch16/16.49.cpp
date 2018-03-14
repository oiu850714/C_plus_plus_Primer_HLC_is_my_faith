template <typename T> void f(T);
template <typename T> void f(const T *);
template <typename T> void g(T);
template <typename T> void g(T *);
int i = 42, *p = &i;
const int ci = 0, *p2 = &ci;

int main() {
  g(42); // g(T): g<int>(int)
  g(p);  // g(T*): g<int>(int*)
  g(ci); // g(T): g<int>(int), don't forget that top-level const will be ignored
         // when call by value
  g(p2); // g(T*): g<const int>(const int*)
  f(42); // f(T): f<int>(int)
  f(p);  // f(T): f<int*>(int *), note that f(const T*) need const conversion
  f(ci); // f(T): f<int>(int), don't forget that top-level const will be ignored
         // when call by value
  f(p2); // f(const T*): f<int>(const int*)
}

#include <iostream>
using std::cout;
using std::endl;
template <typename T> void f(T) { cout << "f(T)" << endl; }
template <typename T> void f(const T *) { cout << "f(const T*)" << endl; }
template <typename T> void g(T) { cout << "g(T)" << endl; }
template <typename T> void g(T *) { cout << "g(T*)" << endl; }