#ifndef _TEXT_QUERY_H_
#define _TEXT_QUERY_H_

#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>

class TextQuery;
class QueryResult;

std::ostream& print(std::ostream &os, const QueryResult &result);
void runQueries(std::istream &is);

class QueryResult {
    friend std::ostream& print(std::ostream &, const QueryResult &);

    public:
        QueryResult(const std::string&, std::shared_ptr<std::vector<std::string>>, std::shared_ptr<std::set<size_t>>);
        std::set<size_t>::iterator begin() { return resultLines_->begin(); }
        std::set<size_t>::const_iterator begin() const { return resultLines_->cbegin(); }
        std::set<size_t>::iterator end() { return resultLines_->end(); }
        std::set<size_t>::const_iterator end() const { return resultLines_->cend(); }
        std::shared_ptr<std::vector<std::string>> get_file() { return files_; }
        std::shared_ptr<const std::vector<std::string>> get_file() const { return files_; }

    private:
        const std::string word;
        std::shared_ptr<std::vector<std::string>> files_;
        std::shared_ptr<std::set<size_t>> resultLines_;
};

class TextQuery {

    public:
        TextQuery(std::istream &is);
        QueryResult query(const std::string &) const;
    private:
        std::shared_ptr<std::vector<std::string>> files_;
        std::map<std::string, std::shared_ptr<std::set<size_t>>> queryStruct_;
};
#endif
