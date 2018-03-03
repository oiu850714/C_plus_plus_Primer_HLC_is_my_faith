#include <iostream>
#include <string>
#include <utility>
class Book;

std::ostream &operator<<(std::ostream &, const Book &);
std::istream &operator>>(std::istream &, const Book &);
bool operator==(const Book &, const Book &);
bool operator!=(const Book &, const Book &);

// ex 14.19
bool operator<(const Book &, const Book &);
bool operator<=(const Book &, const Book &);
bool operator>(const Book &, const Book &);
bool operator>=(const Book &, const Book &);

class Book {
  friend std::ostream &operator<<(std::ostream &, const Book &);
  friend std::istream &operator>>(std::istream &, Book &);
  friend bool operator==(const Book &, const Book &);
  friend bool operator!=(const Book &, const Book &);

  // ex 14.19
  friend bool operator<(const Book &, const Book &);
  friend bool operator<=(const Book &, const Book &);
  friend bool operator>(const Book &, const Book &);
  friend bool operator>=(const Book &, const Book &);

public:
  Book(std::string _name = "", std::string _isbn = "9-999-99999",
       std::string _publisher = "")
      : name(_name), isbn(_isbn), publisher(_publisher) {}

  // ex 14.24
  Book &operator=(const Book &);
  Book &operator=(Book &&);

private:
  std::string name;
  std::string isbn;
  std::string publisher;
};

std::ostream &operator<<(std::ostream &os, const Book &book) {
  os << book.name << " " << book.isbn << " " << book.publisher;
  return os;
}

std::istream &operator>>(std::istream &is, Book &book) {
  is >> book.name >> book.isbn >> book.publisher;
  if (!is)
    book = Book();
  return is;
}

bool operator==(const Book &lhs, const Book &rhs) {
  return lhs.isbn == rhs.isbn; // isbn is unique for each book
}
bool operator!=(const Book &lhs, const Book &rhs) { return !(lhs == rhs); }

// ex 14.19
bool operator<(const Book &lhs, const Book &rhs) { return lhs.isbn < rhs.isbn; }
bool operator<=(const Book &lhs, const Book &rhs) {
  return !(rhs.isbn < lhs.isbn);
}
bool operator>(const Book &lhs, const Book &rhs) { return rhs.isbn < lhs.isbn; }
bool operator>=(const Book &lhs, const Book &rhs) {
  return !(lhs.isbn < rhs.isbn);
}

// ex 14.24
Book &Book::operator=(const Book &rhs) {
  if (this != &rhs) {
    name = rhs.name;
    isbn = rhs.isbn;
    publisher = rhs.publisher;
  }
  return *this;
}
Book &Book::operator=(Book &&rhs) {
  if (this != &rhs) {
    name = std::move(rhs.name);
    isbn = std::move(rhs.isbn);
    publisher = std::move(rhs.publisher);
  }
  return *this;
}