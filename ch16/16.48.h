#include <sstream>
#include <string>
using std::ostringstream;
using std::string;

// declare first, eliminate problem described in Primer P.698-699
string debug_rep(const string &s);
string debug_rep(char *p);
string debug_rep(const char *p);
template <typename T> string debug_rep(const T &t);
template <typename T> string debug_rep(T *p);

string debug_rep(const string &s) { return '"' + s + '"'; }

template <typename T> string debug_rep(const T &t) {
  ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename T> string debug_rep(T *p) {
  ostringstream ret;
  ret << "pointer: " << p;
  if (p)                         // print the pointer's own value
    ret << " " << debug_rep(*p); // print the value to which p points
  else
    ret << " null pointer"; // or indicate that the pis null
  return ret.str();         // return a copy ofthe string to which ret is bound
}

string debug_rep(char *p) { return debug_rep(string(p)); }
string debug_rep(const char *p) { return debug_rep(string(p)); }