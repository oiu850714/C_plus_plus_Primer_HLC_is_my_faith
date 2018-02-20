#include "13.44.h"

#include <algorithm>
#include <memory>
#include <utility>

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
  end = p.second;
}

String::String(const char *s) {
  const char *s1 = s;
  while (*s1++) // find '\0'
    ;
  // after loop, s1 points '\0', we need '\0', so let s1 point after '\0'
  range_initialize(s, ++s1);
}

String::String(const String &Str) { range_initialize(Str.elements, Str.end); }

void String::free() {
  if (elements) {
    for_each(elements, end, [this](char &c) { alloc.destroy(&c); });
  }
}

String::~String() { free(); }

String &String::operator=(const String &Str) {
  auto newptr_pair = alloc_n_copy(Str.elements, Str.end);
  free();
  elements = newptr_pair.first;
  end = newptr_pair.second;

  return *this;
}