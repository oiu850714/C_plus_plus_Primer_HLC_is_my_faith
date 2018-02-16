#include "12.27.h"

TextQuery::TextQuery(std::ifstream &is) {
  std::string line;
  int line_num = 0;
  while (std::getline(is, line)) {
    lines.push_back(line);
    parse_line(line, line_num++);
  }
}

void TextQuery::parse_line(const std::string &line, const int line_num) {
  std::istringstream istrstm(line);
  std::string word;
  while (istrstm >> word) {
    word_map[word].insert(line_num);
  }
}

QueryResult::QueryResult(const TextQuery &tq, const std::string &s = "lol")
    : line_it(tq.lines.begin()), query_string(s) {
  auto p = tq.word_map.find(s);
  if (p != tq.word_map.end()) {
    find_times = p->second.size();
    bResultFind = true;
    set_it_begin = p->second.begin();
    set_it_end = p->second.end();
  } else {
    find_times = 0;
    bResultFind = false;
  }
}

QueryResult TextQuery::query(const std::string &s) const {
  QueryResult qry(*this, s);
  return qry;
}

std::ostream &print(std::ostream &os, const QueryResult &qry) {
  if (qry.bResultFind) {
    std::cout << qry.query_string << " find " << qry.find_times << " time"
              << (qry.find_times > 1 ? "s" : "") << std::endl;
    for (auto it = qry.set_it_begin; it != qry.set_it_end; it++) {
      os << "(line " << *it + 1 /*line numbers are 1-base*/ << ") ";
      os << qry.line_it[*it] << std::endl;
    }
  } else {
    os << "word not found" << std::endl;
  }
  return os;
}