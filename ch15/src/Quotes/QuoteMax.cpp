#include <src/Quotes/QuoteMax.h>
#include <iostream>

QuoteMax::QuoteMax(const std::string &Title, double Price, size_t Quantity, double Discount) :
    DiscQuote(Title, Price, Quantity, Discount) {
}

double QuoteMax::netPrice(size_t PurchaseQuantity) const {
    if (PurchaseQuantity <= Quantity_) {
        return (1 - Discount_) * Price_ * PurchaseQuantity;
    } else {
        return Price_ * ((1 - Discount_) * (Quantity_) + (PurchaseQuantity - Quantity_));
    }
}

std::ostream& QuoteMax::debug(std::ostream& Os) const {
    return Quote::debug(Os) << ", Discount: " << Discount_ << ", MaximumQuantity: " << Quantity_;
}
