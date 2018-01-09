#include <iostream>

int main()
{
    int small = 0, large = 0;
    std::cin >> small >> large;
    if(small > large)
    {
        int temp = small;
        small = large;
        large = temp;
    }

    while(small <= large)
    {
        std::cout << small++ << std::endl;
    }

    return 0;
}