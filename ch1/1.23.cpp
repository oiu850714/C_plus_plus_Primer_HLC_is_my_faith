#include <iostream>
#include "include/Sales_item.h"

int main()
{
    Sales_item cur_item, new_item;
    int has_input_one_item_flag = 0;
    int num_transactions = 0;
    while(std::cin >> new_item)
    {
        if(cur_item.isbn() == new_item.isbn())
        {
            cur_item += new_item;
            num_transactions++;
        }
        else
        {
            if(has_input_one_item_flag)
            {
                std::cout << "number of transactions: " << num_transactions << std::endl;
                std::cout << cur_item << std::endl;
            }
            else
            {
                has_input_one_item_flag = 1;
                num_transactions = 1;
            }
            num_transactions = 1;
            cur_item = new_item;
        }
    }
    if(has_input_one_item_flag)
    {   std::cout << "number of transactions: " << num_transactions << std::endl;
        std::cout << cur_item << std::endl;
        return 0;
    }
    else
    {
        std::cout << "No data?!" << std::endl;
        return 1;
    }
}