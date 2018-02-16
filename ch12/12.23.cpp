#include <cstring>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

char *add_two_C_str(char *s1, char *s2) {
  char *ret = new char[std::strlen(s1) + std::strlen(s2) + 1];
  std::strncpy(ret, s1, strlen(s1));
  std::strncpy(ret + strlen(s1), s2, strlen(s2));
  return ret;
}

string add_two_string(const string &s1, const string &s2) { return s1 + s2; }
int main() {
  char s1[] = "Hsilu", s2[] = " Cute";
  char *s3 = add_two_C_str(s1, s2);
  cout << s3 << endl;
  cout << add_two_string(s1, s2) << endl; // implicitly convert to std::string

  delete[] s3; // don't forget to delete!!
}