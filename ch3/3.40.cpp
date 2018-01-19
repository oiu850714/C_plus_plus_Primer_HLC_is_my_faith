#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::scanf;
using std::strcmp;
using std::strncpy;
using std::strncat;

int main() {
  char s1[4096], s2[4096];
  scanf("%s%s", s1, s2);
  char s3[8192];
  strncpy(s3, s1, 4096);
  strncat(s3, s2, 4096);
  s3[8191] = '\0';
  cout << s3 << endl;
}