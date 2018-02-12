// StrBlob 的 shared_ptr 會被 assign，reference count + 1
// 且兩個 StrBlob objects 的 shared_ptr 會指向同一塊記憶體，changing one affects
// the other StrBlobPtr 的 weak_ptr 也會被 assign，但 reference count 不會增加
// 且兩的 StrBlobPtr objects 的 weak_ptr 也指向同一塊記憶體(同個 element)

// from 12.22.cpp
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

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il)
    : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
  if (i >= data->size())
    throw out_of_range(msg);
}

string &StrBlob::front() {
  // if the vector is empty, check will throw
  check(0, "front on empty StrBlob");
  return data->front();
}

string &StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

const string &StrBlob::front() const {
  // if the vector is empty, check will throw
  check(0, "front on empty StrBlob");
  return data->front();
}

const string &StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

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

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
  auto ret = wptr.lock();
  // is the vector still around?
  if (!ret)
    throw std::runtime_error("unbound StrBlobPtr");
  if (i >= ret->size())
    throw std::out_of_range(msg);
  return ret; // otherwise, return a shared_ptrto the vector
}
std::string &StrBlobPtr::deref() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
  // (*p)is the vectorto which this object points
}
// prefix: return a reference to the incremented object
StrBlobPtr &StrBlobPtr::incr() {
  // if curr already points past the end of the container, can’t increment it
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  // advance the current state return *this;
}

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

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
  auto ret = wptr.lock();
  // is the vector still around?
  if (!ret)
    throw std::runtime_error("unbound StrBlobPtr");
  if (i >= ret->size())
    throw std::out_of_range(msg);
  return ret; // otherwise, return a shared_ptrto the vector
}
const std::string &ConstStrBlobPtr::deref() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
  // (*p)is the vectorto which this object points
}
// prefix: return a reference to the incremented object
ConstStrBlobPtr &ConstStrBlobPtr::incr() {
  // if curr already points past the end of the container, can’t increment it
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  // advance the current state return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::end() const {
  return ConstStrBlobPtr(*this, data->size());
}
