#ifndef _12_32_H_
#define _12_32_H_

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "../12.22.h"

class QueryResult; // declaration needed for return type in the query function
class TextQuery {
public:
  using line_no = std::vector<std::string>::size_type;
  TextQuery(std::ifstream &);
  QueryResult query(const std::string &) const;

private:
  std::shared_ptr<StrBlob> file; // input file
  // map of each word to the set of the lines in which that word appears
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
  friend std::ostream &print(std::ostream &, const QueryResult &);

public:
  QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p,
              std::shared_ptr<StrBlob> f)
      : sought(s), lines(p), file(f) {}

private:
  std::string sought; // word this query represents
  std::shared_ptr<std::set<TextQuery::line_no>> lines; // lines it’s on
  std::shared_ptr<StrBlob> file;                       // input file
};

std::ostream &print(std::ostream &, const QueryResult &);

#endif