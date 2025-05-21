#include <iostream>

int main()
{
    int b = 7;
    auto lambdafn = [&](int a)
    {
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        b = 11;
    };

    int val = [&]()
    { return 20; }();
    lambdafn(10);
    std::cout << b << std::endl;
    return 0;
}