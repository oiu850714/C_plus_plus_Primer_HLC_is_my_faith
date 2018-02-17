#include "12.22.h"
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
  // (*p)is the vector to which this object points
}
// prefix: return a reference to the incremented object
StrBlobPtr &StrBlobPtr::incr() {
  // if curr already points past the end of the container, can’t increment it
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  // advance the current state
  return *this;
}

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
  // advance the current state
  return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::end() const {
  return ConstStrBlobPtr(*this, data->size());
}