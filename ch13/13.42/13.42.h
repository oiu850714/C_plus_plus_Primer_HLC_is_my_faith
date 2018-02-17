#ifndef _12_42_H_
#define _12_42_H_

#include "../13.40.h"

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
  using line_no = StrVec::size_type;
  TextQuery(std::ifstream &);
  QueryResult query(const std::string &) const;

private:
  std::shared_ptr<StrVec> file; // input file
  // map of each word to the set of the lines in which that word appears
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
  friend std::ostream &print(std::ostream &, const QueryResult &);

public:
  using iterator = std::set<TextQuery::line_no>::iterator;
  using const_iterator = std::set<TextQuery::line_no>::const_iterator;
  QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p,
              std::shared_ptr<StrVec> f)
      : sought(s), lines(p), file(f) {}

  // ex 12.33
  iterator begin() { return lines->begin(); }
  const_iterator begin() const { return lines->begin(); };
  iterator end() { return lines->end(); }
  const_iterator end() const { return lines->end(); };

  auto get_file() -> std::shared_ptr<StrVec> { return file; }

private:
  std::string sought; // word this query represents
  std::shared_ptr<std::set<TextQuery::line_no>> lines; // lines it’s on
  std::shared_ptr<StrVec> file;                        // input file
};

std::ostream &print(std::ostream &, const QueryResult &);

#endif