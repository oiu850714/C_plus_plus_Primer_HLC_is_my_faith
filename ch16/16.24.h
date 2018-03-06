#ifndef _16_24_H_
#define _16_24_H_

#include <memory>
#include <string>
#include <vector>

// forward declarations needed for friend declarations in Blob
template <typename> class BlobPtr;
template <typename> class Blob; // needed for parameters in operator==
template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T> class Blob {

  friend class BlobPtr<T>;
  friend bool operator==<T>(const Blob<T> &, const Blob<T> &);

public:
  typedef T value_type;
  typedef typename std::vector<T>::size_type size_type;
  // constructors
  Blob();
  Blob(std::initializer_list<T> il);
  // number of elements in the Blob
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  // add and remove elements
  void push_back(const T &t) { data->push_back(t); }
  // move version; see § 13.6.3 (p. 548)
  void push_back(T &&t) { data->push_back(std::move(t)); }
  void pop_back();
  T &back();
  const T &back() const;
  T &front();
  const T &front() const;
  // element access T& back();
  T &operator[](size_type i); // defined in § 14.5 (p. 566)
  const T &operator[](size_type i) const;

  // ex 16.24
  template <typename It> // type parameter for the constructor
  Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)) {}

private:
  std::shared_ptr<std::vector<T>> data; // throws msg if data[i] isn’t valid
  void check(size_type i, const std::string &msg) const;
};

// BlobPtr throws an exception on attempts to access a nonexistent element
template <typename T> class BlobPtr {
public:
  BlobPtr() : curr(0) {}
  BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  T &operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; // (*p)is the vector to which this object points
  }
  // increment and decrement
  BlobPtr &operator++();
  BlobPtr &operator--();
  // prefix operators

  BlobPtr operator++(int);
  BlobPtr operator--(int);

private: // check returns a shared_ptr to the vector if the check succeeds
  std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
  // store a weak_ptr, which means the underlying vector might be destroyed
  std::weak_ptr<std::vector<T>> wptr;
  std::size_t curr; // current position within the array
};

template <typename T> bool operator==(const Blob<T> &b1, const Blob<T> &b2) {
  return *b1.data == *b2.data;
}

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il)
    : data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
  if (i >= data->size())
    throw std::out_of_range(msg);
}

template <typename T> T &Blob<T>::back() {
  check(0, "back on empty Blob");
  return data->back();
}

template <typename T> const T &Blob<T>::back() const {
  check(0, "back on empty Blob");
  return data->back();
}

template <typename T> T &Blob<T>::front() {
  check(0, "back on empty Blob");
  return data->front();
}

template <typename T> const T &Blob<T>::front() const {
  check(0, "back on empty Blob");
  return data->front();
}

template <typename T> T &Blob<T>::operator[](size_type i) {
  // if i is too big, check will throw, preventing access to a non existent
  // element
  check(i, "subscript out of range");
  return (*data)[i];
}

template <typename T> const T &Blob<T>::operator[](size_type i) const {
  // if i is too big, check will throw, preventing access to a non existent
  // element
  check(i, "subscript out of range");
  return (*data)[i];
}

template <typename T> void Blob<T>::pop_back() {
  check(0, "pop_back on empty Blob");
  data->pop_back();
}

template <typename T> BlobPtr<T> &BlobPtr<T>::operator++() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

template <typename T> BlobPtr<T> &BlobPtr<T>::operator--() {
  --curr;
  check(curr, "decrement past begin of StrBlobPtr");
  return *this;
}

// postfix: increment/decrement the object but return the unchanged value
template <typename T> BlobPtr<T> BlobPtr<T>::operator++(int) {
  //^ not in scope       ^ in scope
  // no check needed here; the call to prefix increment will do the check
  BlobPtr ret = *this; // save the current value
  ++*this;             // advance one element; prefix ++ checks the increment
  return ret;          // return the saved state
}

template <typename T> BlobPtr<T> BlobPtr<T>::operator--(int) {
  BlobPtr ret = *this;
  --*this;
  return ret;
}

template <typename T>
std::shared_ptr<std::vector<T>>
BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
  auto ret = wptr.lock();
  // is the vector still around?
  if (!ret)
    throw std::runtime_error("unbound StrBlobPtr");
  if (i >= ret->size())
    throw std::out_of_range(msg);
  return ret; // otherwise, return a shared_ptrto the vector
}

#endif