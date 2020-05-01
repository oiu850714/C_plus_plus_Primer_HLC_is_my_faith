#ifndef _QUOTE_H_
#define _QUOTE_H_
#include <string>
#include <iostream>

class Quote {
public:
    std::string isbn() const { return Title_; }
    virtual double netPrice(size_t Amount) const { return Amount * Price_; };

    Quote() = default;
    Quote(const std::string &Title, double SalesPrice) : Title_(Title), Price_(SalesPrice) {}

    Quote(const Quote &Q) : Title_(Q.Title_), Price_(Q.Price_) {
        std::cout << "in Quote copy ctor" << std::endl;
    } 
    Quote(Quote &&Q) : Title_(std::move(Q.Title_)), Price_(Q.Price_) {
        std::cout << "in Quote move ctor" << std::endl;
    }

    Quote& operator=(const Quote &Rhs) {
        std::cout << "in Quote copy assign" << std::endl;
        Title_ = Rhs.Title_;
        Price_ = Rhs.Price_;

        return *this;
    }

    Quote& operator=(Quote &&Rhs) {
        std::cout << "in Quote move assign" << std::endl;
        Title_ = std::move(Rhs.Title_);
        Price_ = Rhs.Price_;

        return *this;
    }

    virtual ~Quote() {}

    virtual std::ostream& debug(std::ostream &) const;

    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone() && { return new Quote(std::move(*this)); }
private:
    std::string Title_;

protected:
    double Price_ = 0.0;
};

double PrintTotal(std::ostream& Os, const Quote& Q, size_t Amount);
#endif
