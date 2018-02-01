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

class StrBlob {
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

/*
string &StrBlob::front() const {
  // if the vector is empty, check will throw
  check(0, "front on empty StrBlob");
  return data->front();
}

string &StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}
*/
// Above is a reminder that in this case, return type can be plain reference,
// because const member funtion only applies top-level const on object's
// members, If member is reference or pointer(or shared_ptr thas has
// operator*()), its low-level const will not be changed. So object member,
// data's low-level is nonconst, we can return data->front() and data->back() as
// plain reference.
// link below maybe help
// https://stackoverflow.com/questions/5055427/returning-non-const-reference-from-a-const-member-function
// https://stackoverflow.com/questions/20725190/operating-on-dynamic-memory-is-it-meaningful-to-overload-a-const-memeber-functi

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

int main() {
  const StrBlob csb{"hello", "world", "pezy"};
  StrBlob sb{"hello", "world", "Mooophy"};

  std::cout << csb.front() << " " << csb.back() << std::endl;
  sb = csb;
  // sb = csb -> now sb's pointer points to same object csb's pointer points,
  // LOL
  std::cout << sb.front() << " " << sb.back() << std::endl;
  sb.back() = "csb's data is changed!";
  std::cout << csb.front() << " " << csb.back() << std::endl;
}