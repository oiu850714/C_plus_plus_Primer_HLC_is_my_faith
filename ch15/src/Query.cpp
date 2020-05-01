#include <src/Query.h>
#include <src/QueryBase.h>

#include <memory>

std::ostream& operator<<(std::ostream &Os, const Query &Q) {
    return Os << Q.rep();
}

Query operator~(const Query &Operand) {
    return std::shared_ptr<QueryBase>(new NotQuery(Operand));
}

Query operator&(const Query &Lhs, const Query &Rhs) {
    return std::shared_ptr<QueryBase>(new AndQuery(Lhs, Rhs));
}

Query operator|(const Query &Lhs, const Query &Rhs) {
    return std::shared_ptr<QueryBase>(new OrQuery(Lhs, Rhs));
}

Query::Query(const std::string &word) : Qb_(std::shared_ptr<QueryBase>(new WordQuery(word))) {
}

Query::Query(std::shared_ptr<QueryBase> Query): Qb_(Query) {}
std::string Query::rep() const { return Qb_->rep(); }
QueryResult Query::eval(const TextQuery &DB) const { return Qb_->eval(DB); }