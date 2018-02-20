// refer to: https://github.com/Mooophy/Cpp-Primer/blob/master/ch13/ex13_48.cpp

#include "13.47.h"
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
  char text[] = "world";

  String s0;
  String s1("hello");
  String s2(s0);  // copy cstr
  String s3 = s1; // copy cstr
  String s4(text);
  s2 = s1; // copy assignment

  foo(s1); // copy cstr
  bar(s1);
  cout << "elision?\n";
  foo("temporary"); // copy cstr, or copy elision..??
  bar("temporary");
  String s5 = baz(); // copy ellision, only call String::String(const char*)

  cout << "---------------------------\n";
  std::vector<String> svec;
  svec.reserve(8);
  // reserve is required, otherwise when vector reallocates it
  // will call copy constructor more times, and mess up our outputs

  // void push_back (const value_type& val);
  svec.push_back(s0); // copy cstr
  svec.push_back(s1); // copy cstr
  svec.push_back(s2); // copy cstr
  svec.push_back(s3); // copy cstr
  svec.push_back(s4); // copy cstr
  svec.push_back(s5); // copy cstr
  cout << "elision?\n";
  svec.push_back(baz()); // parameter using copy elision, but, it use copy cstr
                         // to initialize object at vector's allocated memory
  svec.push_back("good job"); // same as above

  for (const auto &s : svec) {
    std::cout << s.c_str() << std::endl;
  }
}