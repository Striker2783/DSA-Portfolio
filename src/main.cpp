#include "list.h"
#include <iostream>

#include <vector>
int main()
{
    List<int> list(1);
    for (size_t i = 0; i < 30; i++)
    {
        list.push_back(i);
    }

    return 0;
}