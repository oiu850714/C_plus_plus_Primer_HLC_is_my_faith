#ifndef _QUERY_BASE_H_
#define _QUERY_BASE_H_
#include <string>

#include <src/TextQuery.h>

class Query;

class QueryBase {
    friend class Query;

protected:
    using line_no = size_t;
    virtual ~QueryBase() = default;
private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

class WordQuery : public QueryBase {
    friend class Query;
private:
    WordQuery(const std::string &word) : QueryWord_(word) {}

    std::string rep() const override { return QueryWord_; }
    QueryResult eval(const TextQuery &DB) const override { return DB.query(QueryWord_); }

protected:
    std::string QueryWord_;
};

class NotQuery : public QueryBase {
    friend class Query;
    friend Query operator~(const Query &);

private:
    NotQuery(const Query &Operand) : Operand_(Operand) {}
    std::string rep() const override { return "~(" + Operand_.rep() + ")"; }
    QueryResult eval(const TextQuery &DB) const override;
    Query Operand_;
};

class BinaryQuery : public QueryBase {
    friend class Query;

protected:
    BinaryQuery(const Query &Lhs, const Query &Rhs, std::string Symbol):
        Lhs_(Lhs), Rhs_(Rhs), Symbol_(Symbol) {}
    std::string rep() const override {
        return "(" + Lhs_.rep() + Symbol_ + Rhs_.rep() + ")";
    }

protected:
    std::string Symbol_;
    Query Lhs_;
    Query Rhs_;
};


class AndQuery : public BinaryQuery {
    friend class Query;
    friend Query operator&(const Query &, const Query &);
private:
    AndQuery(const Query &Lhs, const Query &Rhs) : BinaryQuery(Lhs, Rhs, "&") {}
    QueryResult eval(const TextQuery &) const override;
};

class OrQuery : public BinaryQuery {
    friend class Query;
    friend Query operator|(const Query &, const Query &);
private:
    OrQuery(const Query &Lhs, const Query &Rhs) : BinaryQuery(Lhs, Rhs, "|") {}
    QueryResult eval(const TextQuery &) const override;
};

#include <memory>
#endif