// SEE:https://github.com/chenshuo/recipes/blob/fcf9486f5155117fb8c36b6b0944c5486c71c421/string/StringTrivial.h
// OR: https://github.com/Mooophy/Cpp-Primer/blob/master/ch13/ex13_44_47.h

#ifndef _14_7_H_
#define _14_7_H_
#include <iostream>
#include <memory>

class String;

// ex 14.7
std::ostream &operator<<(std::ostream &, const String &);

class String {
  // ex 14.7
  friend std::ostream &operator<<(std::ostream &, const String &);

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
  size_t size() const { return end - elements; }

private:
  std::pair<char *, char *> alloc_n_copy(const char *, const char *);
  void range_initialize(const char *, const char *);
  void free();

  char *elements;
  char *end;
  std::allocator<char> alloc;
};
#endif