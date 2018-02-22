// SEE:https://github.com/chenshuo/recipes/blob/fcf9486f5155117fb8c36b6b0944c5486c71c421/string/StringTrivial.h
// OR: https://github.com/Mooophy/Cpp-Primer/blob/master/ch13/ex13_44_47.h

#ifndef _STRING_H_
#define _STRING_H_
#include <memory>

class String;

// ex 14.16
bool operator==(const String &, const String &);
bool operator!=(const String &, const String &);

// ex 14.18
bool operator<(const String &lhs, const String &rhs);
bool operator>(const String &lhs, const String &rhs);
bool operator>=(const String &lhs, const String &rhs);
bool operator<=(const String &lhs, const String &rhs);

class String {
  friend bool operator==(const String &, const String &);
  friend bool operator!=(const String &, const String &);

  // ex 14.18
  friend bool operator<(const String &lhs, const String &rhs);
  friend bool operator>(const String &lhs, const String &rhs);
  friend bool operator>=(const String &lhs, const String &rhs);
  friend bool operator<=(const String &lhs, const String &rhs);

public:
  String();
  String(const char *);
  String(const String &);
  String &operator=(const String &);
  ~String();

  // ex 13.49
  String(String &&) noexcept;
  String &operator=(String &&) noexcept;
  void move_pointer(String &Str) noexcept;

  const char *c_str() const { return elements; }
  size_t size() const { return ends - elements; }

  // ex 14.16
  const char *begin() const { return elements; }
  char *begin() { return elements; }
  const char *end() const { return ends_after_null; }
  char *end() { return ends; }

private:
  std::pair<char *, char *> alloc_n_copy(const char *, const char *);
  void range_initialize(const char *, const char *);
  void free();

  char *elements;
  char *ends_after_null;
  char *ends;
  std::allocator<char> alloc;
};
#endif