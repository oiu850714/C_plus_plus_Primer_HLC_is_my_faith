#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::stable_partition;
using std::partition;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;

void printVec(const vector<string> &vec_str) {
  for (const auto &str : vec_str)
    cout << str << " ";
  cout << endl;
}

void elimDups(vector<string> &vec_str) {
  sort(begin(vec_str), end(vec_str));
  vec_str.erase(unique(begin(vec_str), end(vec_str)), vec_str.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
  elimDups(words); // put words in alphabetical order and remove duplicates
  // sort wordsby size, but maintain alphabetical order for words of the same
  // size
  stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
    return a.size() < b.size();
  });
  // get an iterator to the first element whose size() is >= sz
  auto wc =
      stable_partition(words.begin(), words.end(),
                       [sz](const string &str) { return str.size() < sz; });
  // compute the number of elements with size >= sz
  auto count = words.end() - wc;
  cout << count << " " << (count > 1 ? "words" : "word") << " of length " << sz
       << " or longer" << endl;
  // print words of the given size or longer, each one followed by a space
  for_each(wc, words.end(), [](const string &s) { cout << s << " "; });
  cout << endl;
}

int main() {
  std::vector<std::string> vec_str{"the",  "quick", "red",  "fox", "jumps",
                                   "over", "the",   "slow", "red", "turtle"};
  biggies(vec_str, 4);
}