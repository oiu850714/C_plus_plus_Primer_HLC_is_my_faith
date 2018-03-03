#ifndef _STRBLOB_H_
#define _STRBLOB_H_

#include <exception>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::string;
using std::shared_ptr;
using std::unique_ptr;
using std::initializer_list;
using std::make_shared;
using std::out_of_range;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

class StrBlobPtr;
class StrBlob;

// ex 14.30
class ConstStrBlobPtr;

// ex 14.16
bool operator==(const StrBlob &lhs, const StrBlob &rhs);
bool operator!=(const StrBlob &lhs, const StrBlob &rhs);

// ex 14.18
bool operator<(const StrBlob &lhs, const StrBlob &rhs);
bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
bool operator>(const StrBlob &lhs, const StrBlob &rhs);
bool operator>=(const StrBlob &lhs, const StrBlob &rhs);

// ex 14.16
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

// ex 14.18
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

class StrBlob {
  friend class StrBlobPtr;

  // ex 14.30
  friend class ConstStrBlobPtr;

  friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
  friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
  // ex 14.18
  friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
  friend bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
  friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);
  friend bool operator>=(const StrBlob &lhs, const StrBlob &rhs);

public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  // add and remove elements
  void push_back(const std::string &t) { data->push_back(t); }
  // ex 13.55
  void push_back(std::string &&t) { data->push_back(std::move(t)); }
  void pop_back(); // element access
  std::string &front();
  std::string &back();
  const std::string &front() const;
  const std::string &back() const;

  auto just_demo() const -> const std::shared_ptr<std::vector<std::string>> & {
    return data;
  }

  // ex 13.26
  StrBlob(const StrBlob &blob);
  StrBlob &operator=(const StrBlob &blob);

  StrBlobPtr begin();
  StrBlobPtr end();
  ConstStrBlobPtr begin() const;
  ConstStrBlobPtr end() const;

  // ex 14.26
  std::string &operator[](size_t n) { return (*data)[n]; }
  const std::string &operator[](size_t n) const { return (*data)[n]; }

private:
  std::shared_ptr<std::vector<std::string>> data;
  // throws msg if data[i] isn’t valid
  void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
  friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
  // ex 14.18
  friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

public:
  StrBlobPtr() : curr(0) {}
  StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  std::string &deref() const;
  StrBlobPtr &incr();
  // need a function(or operator!=) to compare two StrBlobPtr
  bool equal(const StrBlobPtr &ptr) { return curr == ptr.curr; }
  // prefix version

  // ex 14.26
  std::string &operator[](size_t n);
  const std::string &operator[](size_t n) const;

  // ex 14.27
  StrBlobPtr &operator++();
  StrBlobPtr &operator--();
  StrBlobPtr operator++(int);
  StrBlobPtr operator--(int);

  // ex 14.28
  StrBlobPtr operator+(size_t);
  StrBlobPtr &operator+=(size_t);
  StrBlobPtr operator-(size_t);
  StrBlobPtr &operator-=(size_t);
  StrBlobPtr operator-(const StrBlobPtr &);

  // ex 14.30
  std::string &operator*() const;
  std::string *operator->() const;

private: // check returns a shared_ptr to the vector if the check succeeds
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  // store a weak_ptr, which means the underlying vector might be destroyed
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
  // current position within the array
};

// ex 14.30
class ConstStrBlobPtr {
public:
  ConstStrBlobPtr() : curr(0) {}
  ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  const std::string &deref() const;
  ConstStrBlobPtr &incr();
  // need a function(or operator!=) to compare two StrBlobPtr
  bool equal(const ConstStrBlobPtr &ptr) { return curr == ptr.curr; }
  // prefix version

  // ex 14.30
  const std::string &operator*() const;
  const std::string *operator->() const;

private: // check returns a shared_ptr to the vector if the check succeeds
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  // store a weak_ptr, which means the underlying vector might be destroyed
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
  // current position within the array
};

#endif