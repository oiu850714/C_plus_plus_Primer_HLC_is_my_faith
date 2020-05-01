#ifndef _BULK_QOUTE_H_
#define _BULK_QOUTE_H_
#include <src/DiscQuote.h>

class BulkQuote : public DiscQuote {
public:
    using DiscQuote::DiscQuote; // inherited ctor

    BulkQuote() = default;

    BulkQuote(const BulkQuote &B): DiscQuote(B) {
        std::cout << "in BulkQuote copy ctor" << std::endl;
    }
    BulkQuote(BulkQuote &&B) : DiscQuote(std::move(B)) {
        std::cout << "in BulkQuote move ctor" << std::endl;
    }

    BulkQuote& operator=(const BulkQuote &Rhs) {
        DiscQuote::operator=(Rhs);
        std::cout << "in BulkQuote copy assign" << std::endl;
        return *this;
    }

    BulkQuote& operator=(BulkQuote &&Rhs) {
        DiscQuote::operator=(std::move(Rhs));
        std::cout << "in BulkQuote move assign" << std::endl;
        return *this;
    }

    double netPrice(size_t) const override;
    
    virtual BulkQuote* clone() const & { return new BulkQuote(*this); }
    virtual BulkQuote* clone() && { return new BulkQuote(std::move(*this)); }

    virtual std::ostream& debug(std::ostream&) const override;
};

#endif
