#include <iostream>

int* findValue(int* begin, int* end, int value)
{
    for (int* ptr{ begin }; begin != end; ++ptr)
    {
        if (*ptr == value)
        {
            return ptr;
        }
    }

    return end;
}

#if 0
int main()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    // Search for the first element with value 20.
    int* found{ findValue(std::begin(arr), std::end(arr), 20) };

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }

    return 0;
}
#endif