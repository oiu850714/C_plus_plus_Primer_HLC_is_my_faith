#ifndef _DEBUG_DELETE_H_
#define _DEBUG_DELETE_H_

#include <iostream>

class DebugDelete {
public:
    DebugDelete(std::ostream &Os = std::cerr) : Os_(Os) {}

    template <typename Ptr>
    void operator()(const Ptr& P) const {
        Os_ << "delete ptr: " << std::endl;
        delete P;
    }

private:
    std::ostream &Os_;
};

#endif