#ifndef _QUERY_H_
#define _QUERY_H_

#include "TextQuery.h"
#include <algorithm>
#include <iterator>
#include <memory>
#include <string>

namespace chapter_15 {
class Query;

Query operator~(const Query &);
Query operator|(const Query &, const Query &);
Query operator&(const Query &, const Query &);

// abstract class acts as a base class for concrete query types; all members are
// private
class Query_base {
  friend class Query;

protected:
  using line_no = size_t; // used in the eval functions
  virtual ~Query_base() = default;

private:
  // eval returns the QueryResult that matches this Query
  virtual QueryResult eval(const TextQuery &) const = 0;
  // rep is a string representation of the query
  virtual std::string rep() const = 0;
};

// interface class to manage the Query_base inheritance hierarchy
class Query {
  // these operators need access to the shared_ptr constructor
  friend Query operator~(const Query &);
  friend Query operator|(const Query &, const Query &);
  friend Query operator&(const Query &, const Query &);

public:
  Query(const std::string &); // builds a new WordQuery
  // interface functions: call the corresponding Query_base operations
  QueryResult eval(const TextQuery &t) const { return q->eval(t); }
  std::string rep() const {
    std::cout << "Query::rep\n";
    return q->rep();
  }

private:
  Query(std::shared_ptr<Query_base> query) : q(query) {}
  std::shared_ptr<Query_base> q;
};

class WordQuery : public Query_base {
  friend class Query; // Query uses the WordQuery constructor
  WordQuery(const std::string &s) : query_word(s) {}
  // concrete class: WordQuery defines all inherited pure virtual functions
  QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
  std::string rep() const {
    std::cout << "WordQuery::rep\n";
    return query_word;
  }
  std::string query_word; // word for which to search
};

class NotQuery : public Query_base {
  friend Query operator~(const Query &);
  NotQuery(const Query &q) : query(q) {}
  // concrete class: NotQuery defines all inherited pure virtual functions
  std::string rep() const {
    std::cout << "NotQuery::rep\n";
    return "~(" + query.rep() + ")";
  }
  QueryResult eval(const TextQuery &) const;
  Query query;
};

class BinaryQuery : public Query_base {
protected:
  BinaryQuery(const Query &l, const Query &r, std::string s)
      : lhs(l), rhs(r), opSym(s) {}
  // abstract class: BinaryQuery doesn’t define eval
  std::string rep() const {
    std::cout << "BinaryQuery::rep\n";
    return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
  }
  Query lhs, rhs;    // right- and left-hand operands
  std::string opSym; // name of the operator
};

class AndQuery : public BinaryQuery {
  friend Query operator&(const Query &, const Query &);

  AndQuery(const Query &left, const Query &right)
      : BinaryQuery(left, right, "&") {}
  // concrete class: AndQuery inherits rep and defines the remaining pure
  // virtual
  QueryResult eval(const TextQuery &) const;
};

class OrQuery : public BinaryQuery {
  friend Query operator|(const Query &, const Query &);

  OrQuery(const Query &left, const Query &right)
      : BinaryQuery(left, right, "|") {}
  QueryResult eval(const TextQuery &) const;
};

// Best Practice: put inline function in header
inline Query::Query(const std::string &s) : q(new WordQuery(s)) {}

inline Query operator~(const Query &operand) {
  return std::shared_ptr<Query_base>(new NotQuery(operand));
}

inline Query operator&(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

} // namespace chapter_15

#endif