#include "String.h"

#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>
using std::cout;
using std::endl;
using std::for_each;
using std::allocator;
using std::pair;
using std::uninitialized_copy;

String::String() : String("") { // 這個寫法真的超屌ㄟ
  // need to create empty string
}

pair<char *, char *> String::alloc_n_copy(const char *begin, const char *end) {
  auto str_ptr = alloc.allocate(end - begin);
  return {str_ptr, uninitialized_copy(begin, end, str_ptr)};
}

void String::range_initialize(const char *b, const char *e) {
  auto p = alloc_n_copy(b, e);
  elements = p.first;
  ends_after_null = p.second;
  ends = ends_after_null - 1;
}

String::String(const char *s) {
  const char *s1 = s;
  while (*s1++) // find '\0'
    ;
  range_initialize(s, s1);
}

String::String(const String &Str) {
  cout << "copy cstr\n";
  range_initialize(Str.elements, Str.ends_after_null);
}

void String::free() {
  if (elements) {
    for_each(elements, ends_after_null, [this](char &c) { alloc.destroy(&c); });
  }
}

String::~String() { free(); }

String &String::operator=(const String &Str) {
  cout << "copy assignment\n";
  auto newptr_pair = alloc_n_copy(Str.elements, Str.ends_after_null);
  free();
  elements = newptr_pair.first;
  ends_after_null = newptr_pair.second;
  ends = ends_after_null - 1;
  return *this;
}

// ex 13.49
String::String(String &&Str) noexcept {
  move_pointer(Str);
  cout << "move cstr\n";
}

String &String::operator=(String &&rhs) noexcept {
  if (this != &rhs) {
    free();
    move_pointer(rhs);
  }
  cout << "move assignment\n";
  return *this;
}

void String::move_pointer(String &Str) noexcept {
  elements = Str.elements;
  ends_after_null = Str.ends_after_null;
  Str.elements = Str.ends_after_null = nullptr;
}

// ex 14.16
bool operator==(const String &lhs, const String &rhs) {
  if (lhs.size() != rhs.size())
    return false;
  for (auto l_it = lhs.begin(), r_it = rhs.begin(); l_it != lhs.end();) {
    if (*l_it++ != *r_it++)
      return false;
  }
  return true;
  /* // or you can use std::equal
  return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(),
  rhs.begin()));
  */
}
bool operator!=(const String &lhs, const String &rhs) { return !(lhs == rhs); }

// ex 14.18
// all can be implemented solely using operator<
bool operator<(const String &lhs, const String &rhs) {
  size_t size = (lhs.size() < rhs.size() ? lhs.size() : rhs.size());
  size_t index = 0;
  auto l_it = lhs.begin(), r_it = rhs.begin();
  for (; index != size; ++index) {
    if (*(l_it + index) == *(r_it + index))
      continue;
    else if (*(l_it + index) < *(r_it + index))
      return true;
    else
      return false;
  }
  return lhs.size() < rhs.size() ? true : false; // one if another's substring
}
bool operator>(const String &lhs, const String &rhs) { return rhs < lhs; }
bool operator<=(const String &lhs, const String &rhs) { return !(rhs < lhs); }
bool operator>=(const String &lhs, const String &rhs) { return !(lhs < rhs); }