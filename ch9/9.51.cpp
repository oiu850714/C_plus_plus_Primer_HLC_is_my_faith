// See: https://github.com/Mooophy/Cpp-Primer/blob/master/ch09/ex9_51.cpp

#include <exception>
#include <iostream>
#include <string>

// Just deal with two format Mon,Day,Year and Mon/Day/Year
class Date {
public:
  Date(const std::string &date);
  std::ostream &print(std::ostream &os) {
    os << month << " " << year << " " << day << "\n";
    return os;
  }

private:
  unsigned year;
  unsigned month;
  unsigned day;
};

using std::string;

Date::Date(const std::string &date) {
  const std::string numbers{"0123456789"};
  unsigned format_type = 0;
  // 0x01: format with comma
  // 0x10: format with slash

  if (date.find(",") != string::npos) {
    format_type = 0x01;
  } else if (date.find("/") != string::npos) {
    format_type = 0x10;
  } else {
    throw std::invalid_argument("invalid date formats");
  }

  int pos = 0;
  string month_str;
  switch (format_type) {
  case 0x01:
    month_str =
        date.substr(pos, date.find_first_of(",", pos) - pos); // extract month
    if (month_str.find("Jan") != string::npos)
      month = 1;
    if (month_str.find("Feb") != string::npos)
      month = 2;
    if (month_str.find("Mar") != string::npos)
      month = 3;
    if (month_str.find("Apr") != string::npos)
      month = 4;
    if (month_str.find("May") != string::npos)
      month = 5;
    if (month_str.find("Jun") != string::npos)
      month = 6;
    if (month_str.find("Jul") != string::npos)
      month = 7;
    if (month_str.find("Aug") != string::npos)
      month = 8;
    if (month_str.find("Sep") != string::npos)
      month = 9;
    if (month_str.find("Oct") != string::npos)
      month = 10;
    if (month_str.find("Nov") != string::npos)
      month = 11;
    if (month_str.find("Dec") != string::npos)
      month = 12;
    pos = date.find_first_of(",", pos) + 1;

    day = stoi(
        date.substr(pos, date.find_first_of(",", pos) - pos)); // extract day
    pos = date.find_first_of(",", pos) + 1;

    year = stoi(date.substr(pos)); // extract year
    break;

  case 0x10:
    month = stoi(
        date.substr(pos, date.find_first_of("/", pos) - pos)); // extract month
    pos = date.find_first_of("/", pos) + 1;

    day = stoi(
        date.substr(pos, date.find_first_of("/", pos) - pos)); // extract day
    pos = date.find_first_of("/", pos) + 1;

    year = stoi(date.substr(pos)); // extract year
    break;
  }
}

int main() {
  Date d1("10/30/2015"), d2("Dec,30,2015");
  d1.print(std::cout);
  d2.print(std::cout);
  // Date d3("lol lololol"); // will throw
}