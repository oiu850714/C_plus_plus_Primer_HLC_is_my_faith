#include "StrBlob.h"
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

// ex 13.26

StrBlob::StrBlob(const StrBlob &blob)
    : data(make_shared<vector<string>>(*blob.data)) {}

StrBlob &StrBlob::operator=(const StrBlob &blob) {
  data = make_shared<vector<string>>(*blob.data); // 指向的 vector<string>>
                                                  // 要各自獨立，所以要用
                                                  // make_shared new 一塊新物件
  return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

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
  // advance the current state
  return *this;
}

// ex 14.16
bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
  return *lhs.data == *rhs.data; // check values are the same
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
  return !(lhs == rhs);
}

// ex 14.16
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs.curr ==
         rhs.curr; // just check the position, it will not check whether
                   // two Ptr points to same StrBlob
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs == rhs);
}

// ex 14.18
// all can be implemented solely using operator<
bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
  // SEE:
  // https://github.com/Mooophy/Cpp-Primer/blob/master/ch14/ex14_18_StrBlob.cpp,
  // it uses std::lexicographical_compare I think comparing underlying vectors
  // directly or using lexicographical_compare are both acceptable
  return *lhs.data < *rhs.data;
}
bool operator<=(const StrBlob &lhs, const StrBlob &rhs) { return !(rhs < lhs); }
bool operator>(const StrBlob &lhs, const StrBlob &rhs) { return rhs < lhs; }
bool operator>=(const StrBlob &lhs, const StrBlob &rhs) { return !(lhs < rhs); }

// ex 14.18
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs.curr < rhs.curr;
}
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs.curr <= rhs.curr;
}
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs.curr > rhs.curr;
}
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs.curr >= rhs.curr;
}

// ex 14.26
// see member function definition of "deref"
std::string &StrBlobPtr::operator[](size_t n) {
  auto p = check(curr + n, "dereference past end");
  return (*p)[curr + n];
}
const std::string &StrBlobPtr::operator[](size_t n) const {
  auto p = check(curr + n, "dereference past end");
  return (*p)[curr + n];
}