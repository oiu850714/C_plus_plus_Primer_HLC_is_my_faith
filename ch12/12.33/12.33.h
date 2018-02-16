#ifndef _12_33_H_
#define _12_33_H_

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class QueryResult; // declaration needed for return type in the query function
class TextQuery {
public:
  using line_no = std::vector<std::string>::size_type;
  TextQuery(std::ifstream &);
  QueryResult query(const std::string &) const;

private:
  std::shared_ptr<std::vector<std::string>> file; // input file
  // map of each word to the set of the lines in which that word appears
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
  friend std::ostream &print(std::ostream &, const QueryResult &);

public:
  using iterator = std::set<TextQuery::line_no>::iterator;
  using const_iterator = std::set<TextQuery::line_no>::const_iterator;
  QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p,
              std::shared_ptr<std::vector<std::string>> f)
      : sought(s), lines(p), file(f) {}

  // ex 12.33
  iterator begin() { return lines->begin(); }
  const_iterator begin() const { return lines->begin(); };
  iterator end() { return lines->end(); }
  const_iterator end() const { return lines->end(); };

  auto get_file() -> std::shared_ptr<std::vector<std::string>> { return file; }

private:
  std::string sought; // word this query represents
  std::shared_ptr<std::set<TextQuery::line_no>> lines; // lines it’s on
  std::shared_ptr<std::vector<std::string>> file;      // input file
};

std::ostream &print(std::ostream &, const QueryResult &);

#endif