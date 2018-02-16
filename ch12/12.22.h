#ifndef _12_22_H_
#define _12_22_H_

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
class ConstStrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;

public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  // add and remove elements
  void push_back(const std::string &t) { data->push_back(t); }
  void pop_back(); // element access
  std::string &front();
  std::string &back();
  const std::string &front() const;
  const std::string &back() const;

  auto just_demo() const -> const std::shared_ptr<std::vector<std::string>> & {
    return data;
  }

  StrBlobPtr begin();
  StrBlobPtr end();
  ConstStrBlobPtr begin() const;
  ConstStrBlobPtr end() const;

private:
  std::shared_ptr<std::vector<std::string>> data;
  // throws msg if data[i] isn’t valid
  void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
public:
  StrBlobPtr() : curr(0) {}
  StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  std::string &deref() const;
  StrBlobPtr &incr();
  // need a function(or operator!=) to compare two StrBlobPtr
  bool equal(const StrBlobPtr &ptr) { return curr == ptr.curr; }
  // prefix version
private: // check returns a shared_ptr to the vector if the check succeeds
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  // store a weak_ptr, which means the underlying vector might be destroyed
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
  // current position within the array
};
class ConstStrBlobPtr {
public:
  ConstStrBlobPtr() : curr(0) {}
  ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  const std::string &deref() const;
  ConstStrBlobPtr &incr();
  // need a function(or operator!=) to compare two StrBlobPtr
  bool equal(const ConstStrBlobPtr &ptr) { return curr == ptr.curr; }
  // prefix version
private: // check returns a shared_ptr to the vector if the check succeeds
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  // store a weak_ptr, which means the underlying vector might be destroyed
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
  // current position within the array
};

#endif