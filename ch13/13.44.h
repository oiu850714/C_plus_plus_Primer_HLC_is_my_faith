// SEE:https://github.com/chenshuo/recipes/blob/fcf9486f5155117fb8c36b6b0944c5486c71c421/string/StringTrivial.h
// OR: https://github.com/Mooophy/Cpp-Primer/blob/master/ch13/ex13_44_47.h

#ifndef _13_44_H_
#define _13_44_H_
#include <memory>

class String {
public:
  String();
  String(const char *);
  String(const String &);
  String &operator=(const String &);
  ~String();

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