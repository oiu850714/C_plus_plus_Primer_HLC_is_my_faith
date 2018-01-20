#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::begin;
using std::end;
using std::scanf;
using std::strcmp;
using std::strncpy;
using std::strncat;

int main() {
  string s = "wwwwwwwww9487";
  vector<string> vec = {s};
  auto iter = vec.begin();
  //(a)
  *iter++; // legal: *(iter++);
  //(b)
  (*iter)++; // illegal: *iter is string on which postfix++ cannot apply
  //(c)
  *iter.empty(); // illegal: *(iter.empty()); iter has no member empty
  //(d)
  iter->empty(); // legal: fetch member empty of an string object
  //(e)
  ++*iter; // illegal: *iter is string on which prefix++ cannot apply
  //(f)
  iter++->empty(); // legal: (iter++)->empty(); fetch member empty of string
                   // object to which iter(old value) points to
}