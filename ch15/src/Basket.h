#ifndef _BASKET_H_
#define _BASKET_H_
#include <src/Quote.h>
#include <set>
#include <memory>
#include <iostream>

class Basket {
public:
    void addItem(const Quote&);
    void addItem(Quote &&);

    double totalReceipt(std::ostream& Os) const {
        double Sum = 0.0; // holds the running total
        // Iter refers to the **first element in a batch of elements with the same ISBN**
        // upper_bound returns an iterator to the element **just past the end of that batch**
        for (auto Iter = Items_.cbegin(); 
                Iter != Items_.cend(); 
                Iter = Items_.upper_bound(*Iter)) {
            // we know there’s at least one element with this key in the Basket
            // print the line item for this book 
            Sum += PrintTotal(Os, **Iter, Items_.count(*Iter));
        }
        Os << "Total Sale: " << Sum << std::endl; // print the final overall total 
        return Sum;
    }

private:
    static bool compare_(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare_)*> Items_{compare_};
    // 上面這個是 initializer_list 用再 in-class initializer 的寫法
};

#endif /* _BASKET_H_ */