#include <iostream>

void printCString(const char* ptr)
{
    while (*ptr != '\0')
    {
        std::cout << *ptr;
        ++ptr;
    }
}

int main()
{
    char test[]{ "Hello World!" };
    printCString(test);

    return 0;
}


