#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::string;
using std::vector;

class comp_size {
public:
  bool operator()(const string &a, const string &b) const {
    return a.size() > b.size();
  }
};

class output_string {
public:
  void operator()(const string &s) const { cout << s << " "; }
};

string make_plural(int size, const string &origin, const string &plu) {
  if (size > 1)
    return origin + plu;
  else
    return origin;
}

void elimDups(std::vector<std::string> &vs) {
  std::sort(vs.begin(), vs.end());
  auto new_end = std::unique(vs.begin(), vs.end());
  vs.erase(new_end, vs.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
  elimDups(words); // put words in alphabetical order and remove duplicates
  // sort wordsby size, but maintain alphabetical order for words of the same
  // size
  stable_sort(words.begin(), words.end(), comp_size()); // ex 14.40
  // get an iterator to the first element whose size() is >= sz
  auto wc = find_if(words.begin(), words.end(),
                    [sz](const string &a) { return a.size() >= sz; });
  // compute the number of elements with size >= sz
  auto count = words.end() - wc;
  cout << count << " " << make_plural(count, "word", "s") << " of length " << sz
       << " or longer" << endl;
  // print words of the given size or longer, each one followed by a space
  for_each(wc, words.end(), output_string()); // ex 14.40
  cout << endl;
}