#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::scanf;
using std::strcmp;
using std::string;
using std::strncat;
using std::strncpy;
using std::vector;
using std::isupper;

string::size_type find_char(const string &s, char c, string::size_type &occurs);

// string may be long, we declare it as reference to avoid copy
// if string is plain reference, that means the function can modify the string's
// value, which is not intention we want c is passed by value because c is a
// small object, using reference will add another indirect access, which adds
// additional overhead if occurs is reference to const, the function cannot
// modify it, which is not intention we want