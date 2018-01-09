#include <iostream>

int main()
{
    int result = 0;
    for(int i = 50; i <= 100;)
    {
        result += i++;
    }
    std::cout << "sum(50 to 100): " << result << std::endl;
    return 0;
}