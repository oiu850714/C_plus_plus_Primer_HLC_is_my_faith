#include <iostream>
#include "include/Sales_item.h"

int main()
{
    Sales_item item, item_sum;
    while(std::cin >> item)
    {   
        if(item_sum.isbn() != item.isbn())
        //when input first item, item_sum.isbn() is not set
            item_sum = item;
        else
            item_sum += item;
    }
    std::cout << item_sum << std::endl;
    return 0;
}