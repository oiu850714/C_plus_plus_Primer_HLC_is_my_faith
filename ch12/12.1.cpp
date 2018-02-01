#include <exception>
#include <initializer_list>
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
void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

int main() {
  StrBlob b1;
  {
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
  }
  // b2 will be destroyed
  // b1 will have for elements: {"a", "an", "the", "about"}
}