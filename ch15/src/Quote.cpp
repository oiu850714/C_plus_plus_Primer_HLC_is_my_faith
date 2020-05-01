#include <src/Quote.h>
#include <string>
#include <iostream>

double PrintTotal(std::ostream& Os, const Quote& Q, size_t Amount) {
    Os << "ISBN: " << Q.isbn() << ", price: " << Q.netPrice(Amount) << std::endl;

    return Q.netPrice(Amount);
}

std::ostream& Quote::debug(std::ostream &Os) const {
    return Os << "ISBN: " << isbn() << ", sale price: " << Price_;
}
