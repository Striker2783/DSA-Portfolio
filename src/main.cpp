#include "list.hpp"
#include <iostream>

int main()
{
    List<int> list(1);
    for (size_t i = 0; i < 30; i++)
    {
        list.push_back(i);
    };
    std::cout << list << std::endl;
    std::cout << "Hello Friend \n";
    return 0;
}