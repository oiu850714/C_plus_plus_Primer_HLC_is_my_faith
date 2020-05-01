#ifndef _QUOTE_MAX_H_
#define _QUOTE_MAX_H_
#include <src/DiscQuote.h>
#include <iostream>

class QuoteMax : public DiscQuote {
public:
    QuoteMax() = default;
    QuoteMax(const std::string &, double, size_t, double);

    double netPrice(size_t) const override;

    virtual std::ostream& debug(std::ostream&) const override;
};

#endif
