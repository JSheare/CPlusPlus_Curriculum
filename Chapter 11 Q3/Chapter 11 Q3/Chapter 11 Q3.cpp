#include <iostream>

void swap(int& a, int& b)
{
    int temp{};
    temp = a;
    a = b;
    b = temp;

}

int main()
{
    int a{ 4 };
    int b{ 6 };
    std::cout << a << ' ' << b << '\n';
    swap(a, b);
    std::cout << a << ' ' << b << '\n';

    return 0;
}


