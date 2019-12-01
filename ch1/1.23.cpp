#include "include/Sales_item.h"

int main() {
    Sales_item pre_record, new_record;
    if (std::cin >> pre_record) {
        int count = 1;
        while (std::cin >> new_record) {
            if (pre_record.isbn() == new_record.isbn()) {
                count++;
            } else {
                std::cout << "the book of ISBN " << pre_record.isbn()
                    << " has " << count << " transactions" << std::endl;

                pre_record = new_record;
                count = 1;
            }
        }
        std::cout << "the book of ISBN " << pre_record.isbn()
            << " has " << count << " transactions" << std::endl;
    }
}
