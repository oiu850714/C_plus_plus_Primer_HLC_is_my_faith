#include <iostream>

int main()
{
    std::cout << "Give me a set of numbers, I'll give you the sum:";
    int sum = 0;
    int num = 0;
    while(std::cin >> num)
        sum += num;
    std::cout << "sum: " << sum << std::endl;
    return 0;
}