#include <cctype>
#include <cstdio>
#include <cstring>
#include <initializer_list>
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
using std::isupper;
using std::scanf;
using std::strcmp;
using std::string;
using std::strncat;
using std::strncpy;
using std::vector;
using std::initializer_list;

string (&func1())[10];

string strings[10];

typedef string arr_of_ten_strings[10];
arr_of_ten_strings &func2() { return strings; }
// & 不用跟 func2 括在一起，因為現在就是希望
// func2 的 return type 是 reference to
// arr_of_ten_strings; 要括號也是可以，在這個 case 不會影響 return type

using ten_strings = string[10];
ten_strings &func3() { return strings; }

auto func4() -> string (&)[10] { return strings; }
decltype(strings) &func5() { return strings; }

// I prefer auto and using version because typedef is shitty and decltype need a
// variable outside the function scope which is somewhat not make sense
