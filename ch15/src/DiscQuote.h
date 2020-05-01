#ifndef _DISC_QOUTE_H_
#define _DISC_QOUTE_H_
#include <src/Quote.h>

class DiscQuote : public Quote {
public:
    DiscQuote() {};
    DiscQuote(const std::string &Title, double Price, size_t Quantity, double Discount) :
    Quote(Title, Price), Quantity_(Quantity), Discount_(Discount) {
    }

    DiscQuote(const DiscQuote &) = default;
    DiscQuote(DiscQuote &&) = default;

    DiscQuote& operator=(const DiscQuote &) = default;
    DiscQuote& operator=(DiscQuote &&) = default;

    virtual double netPrice(size_t Amount) const = 0;

protected:
    size_t Quantity_ = 0;
    double Discount_ = 0.0;
};

inline double DiscQuote::netPrice(size_t Amount) const { return 87; }

#endif