#include <src/Query.h>
#include <src/QueryBase.h>
#include <src/TextQuery.h>

#include <memory>
#include <set>
#include <algorithm>
#include <numeric> // std::iota
#include <iterator>

QueryResult NotQuery::eval(const TextQuery &DB) const {
    auto OperandResult = Operand_.eval(DB);
    
    auto getFileLines = [&OperandResult] {
        std::vector<QueryBase::line_no> FileLines(OperandResult.get_file()->size());
        std::iota(FileLines.begin(), FileLines.end(), 0);
        return FileLines;
    };

    auto FileLines = getFileLines();

    auto ReturnLines = std::make_shared<std::set<line_no>>();
    std::set_difference(FileLines.begin(), FileLines.end(),
                        OperandResult.begin(), OperandResult.end(),
                        std::inserter(*ReturnLines, ReturnLines->begin()));

    return QueryResult(rep(), OperandResult.get_file(), ReturnLines);
}

QueryResult AndQuery::eval(const TextQuery &DB) const {
    auto LhsResult = Lhs_.eval(DB), RhsResult = Rhs_.eval(DB);

    auto ReturnLines = std::make_shared<std::set<line_no>>();
    std::set_intersection(LhsResult.begin(), LhsResult.end(),
                            RhsResult.begin(), RhsResult.end(),
                            std::inserter(*ReturnLines, ReturnLines->begin()));

    return QueryResult(rep(), LhsResult.get_file(), ReturnLines);
}

QueryResult OrQuery::eval(const TextQuery &DB) const {
    auto LhsResult = Lhs_.eval(DB), RhsResult = Rhs_.eval(DB);

    auto ReturnLines = std::make_shared<std::set<line_no>>();
    std::set_union(LhsResult.begin(), LhsResult.end(),
                            RhsResult.begin(), RhsResult.end(),
                            std::inserter(*ReturnLines, ReturnLines->begin()));

    return QueryResult(rep(), RhsResult.get_file(), ReturnLines);
}