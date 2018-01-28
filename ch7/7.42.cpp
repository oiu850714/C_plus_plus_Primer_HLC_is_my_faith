// (a) Book
//   member: isbn, bookName, author, publisher, version, price, type
//   cstr: no default cstr, because isbn, bookName, author, publisher, version
//   are required
// SEE:
// https://github.com/Mooophy/Cpp-Primer/tree/master/ch07#exercise-740

#include <iostream>
#include <string>

class Book {

public:
  Book(std::string s_isbn, std::string s_bookName, std::string s_author,
       std::string s_publisher, std::string s_version, std::string s_type)
      : isbn(s_isbn), bookName(s_bookName), author(s_author),
        publisher(s_publisher), version(s_version), type(s_type) {}
  Book(std::string s_isbn, std::string s_bookName, std::string s_author,
       std::string s_publisher)
      : Book(s_isbn, s_bookName, s_author, s_publisher, "1.0", "defalut") {}

  // other utilities

private:
  std::string isbn;
  std::string bookName;
  std::string author;
  std::string publisher;
  std::string version;
  std::string type;
  double price;
};