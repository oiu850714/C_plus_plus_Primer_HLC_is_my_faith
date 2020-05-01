#ifndef _QUERY_H_
#define _QUERY_H_

#include <iostream>
#include <memory>
#include <set>
#include <string>

#include <src/TextQuery.h>

class QueryBase;
class Query;
class Shitty;

std::ostream& operator<<(std::ostream &, const Query &);
Query operator~(const Query&);
Query operator|(const Query&, const Query&);
Query operator&(const Query&, const Query&);

class Query {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string &);
    std::string rep() const;
    QueryResult eval(const TextQuery &DB) const;

private:
    Query(std::shared_ptr<QueryBase> Query);
    std::shared_ptr<QueryBase> Qb_;
};

#endif