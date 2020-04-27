#include <src/TextQuery.h>
#include <src/DebugDelete.h>

TextQuery::TextQuery(std::istream &is) : files_(new std::vector<std::string>, DebugDelete()){
    const auto saveFile = [&is, &files = files_] {
        std::string line;
        while(std::getline(is, line)) {
            files->push_back(line);
        }
    };
    saveFile();

    size_t lineNum = 0;
    std::for_each(files_->begin(), files_->end(), [&lineNum, &queryStruct = queryStruct_] (const std::string &line) {
            std::istringstream istrstm(line);
            std::string word;
            while (istrstm >> word) {
                auto &lines = queryStruct[word];
                if (!lines) {
                    lines.reset(new std::set<size_t>);
                }
                lines->insert(lineNum);
            }
            lineNum++;
        });
}

QueryResult TextQuery::query(const std::string &word) const {
    static std::shared_ptr<std::set<size_t>> nodata(new std::set<size_t>);

    auto it = queryStruct_.find(word);
    if (it != queryStruct_.end()) {
        return QueryResult(word, files_, it->second);
    } else {
        return QueryResult(word, files_, nodata);
    }
}

QueryResult::QueryResult(const std::string &word, std::shared_ptr<std::vector<std::string>> sharedFiles, std::shared_ptr<std::set<size_t>> sharedResultLines)
    : word(word), files_(sharedFiles), resultLines_(sharedResultLines) {
}

void runQueries(std::istream &is) {
    const TextQuery tq(is);

    while (true) {
        std::cout << "type word you want to query(or q to quit):";

        std::string word;
        if (!(std::cin >> word) || "q" == word) {
            std::cout << "bye" << std::endl;
            return;
        }

        print(std::cout, tq.query(word));
    }
}

std::ostream& print(std::ostream &os, const QueryResult &result) {
    os << result.word << " occur " << result.resultLines_->size() << " times" << std::endl;
    for (const auto line : *result.resultLines_) {
        os << "line " << line + 1<< ":" << result.files_->begin()[line] << std::endl;
    }

    return os;
}

