#include <src/Quotes/BulkQuote.h>

double BulkQuote::netPrice(size_t PurchaseQuantity) const {
    if (PurchaseQuantity >= Quantity_) {
        return (1 - Discount_) * Price_ * PurchaseQuantity;
    } else {
        return Price_ * PurchaseQuantity;
    }
}


std::ostream& BulkQuote::debug(std::ostream& Os) const {
    return Quote::debug(Os) << ", Discount: " << Discount_ << ", MinumumQuantity: " << Quantity_;
}
