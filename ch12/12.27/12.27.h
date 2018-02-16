#ifndef _12_27_H_
#define _12_27_H_

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

// Note: in this version I didn't use shared_prr

class TextQuery;
class QueryResult;

class QueryResult {
  friend std::ostream &print(std::ostream &, const QueryResult &);

private:
  std::vector<std::string>::const_iterator line_it;
  std::set<int>::const_iterator set_it_begin, set_it_end;
  bool bResultFind;
  int find_times;
  std::string query_string;

public:
  QueryResult(const TextQuery &, const std::string &s);
};

std::ostream &print(std::ostream &, const QueryResult &);

class TextQuery {

  friend class QueryResult;

private:
  std::vector<std::string> lines;
  std::map<std::string, std::set<int>> word_map;

  // private utilities
  void parse_line(const std::string &line, const int line_num);

public:
  TextQuery(std::ifstream &is);
  QueryResult query(const std::string &) const;

  // debug utility
  void print_line_and_map() {
    std::cout << "text contents:\n";
    for (const auto &s : lines)
      std::cout << s << std::endl;

    std::cout << "\n\n\nquery map:\n";
    for (const auto &e : word_map) {
      std::cout << "word: " << e.first << "  , line_num: ";
      for (auto num : e.second)
        std::cout << num << " ";
      std::cout << std::endl;
    }
  }
};

#endif