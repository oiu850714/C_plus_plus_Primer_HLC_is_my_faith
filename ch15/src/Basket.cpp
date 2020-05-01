#include <src/Quote.h>
#include <src/Basket.h>

void Basket::addItem(const Quote& quote) {
    Items_.insert(std::shared_ptr<Quote>(quote.clone()));
}

void Basket::addItem(Quote&& quote) {
    Items_.insert(std::shared_ptr
    <Quote>(std::move(quote).clone()));
}