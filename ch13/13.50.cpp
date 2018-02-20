// refer to: https://github.com/Mooophy/Cpp-Primer/blob/master/ch13/ex13_48.cpp

#include "13.49/String.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void foo(String x) { std::cout << x.c_str() << std::endl; }

void bar(const String &x) { std::cout << x.c_str() << std::endl; }

String baz() {
  String ret("world");
  return ret;
}

int main() {
  String s1("hello");
  String s2 = s1;           // copy cstr
  String s3 = String("s3"); // move cstr
  cout << s3.c_str() << endl;
  s3 = String("s3 after move assignment"); // move assignment
  cout << s3.c_str() << endl;
  String s4 = baz(); // copy elision, neither move nor copy

  String s5("push_back");
  cout << "-----------------------\n";

  vector<String> svec;
  svec.reserve(10);

  // void push_back (const value_type& val);
  // void push_back (value_type&& val);

  svec.push_back(s1);              // copy
  svec.push_back(String("move1")); // move
}