#include <iostream>
#include <map>
#include <set>
#include <string>

using std::multimap;
using std::map;
using std::set;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
  multimap<string, string> name_to_works{
      {"Hsilu", "teacher"}, {"Hsilu", "Tenshi"}, {"J7", "neet"},
      {"J7", "student"},    {"Peter", "geek"},   {"Peter", "winner"},
      {"Peter", "boss"}};
  map<string, set<string>> author_works_sorted;
  for (const auto &e : name_to_works) {
    author_works_sorted[e.first].insert(e.second);
  }

  for (const auto &per_author_info : author_works_sorted) {
    cout << "author: " << per_author_info.first << endl;
    cout << "works: ";
    for (const auto &work : per_author_info.second)
      cout << work << " ";
    cout << endl;
  }
}