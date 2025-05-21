#include <iostream>
#include <thread>

class Base
{
public:
    void operator()(int x)
    {
        while (x--)
            std::cout << x << std::endl;
    }

    void run(int x)
    {
        while (x--)
            std::cout << x << std::endl;
    }

    static void fun(int x)
    {
        while (x--)
            std::cout << x << std::endl;
    }
};

void fun1(int x)
{
    while (x--)
        std::cout << x << std::endl;
}

// 5 methods of creating a thread in cpp

int main()
{
    // method 1
    std::thread t1(fun1, 10);
    t1.join();

    // method 2 :  lambda function and you can also put lambda function directly into thread
    auto fun2 = [](int x)
    {
        while (x--)
            std::cout << x << std::endl;
    };
    std::thread t2(fun2, 10);
    t2.join();

    // method 3 : Functors
    std::thread t3((Base()), 10);
    t3.join();

    // method 4 : non static member functions
    Base b;
    std::thread t4(&Base::run, &b, 10);
    t4.join();

    // method 5 : static member functions
    std::thread t5(&Base::fun, 10);
    t5.join();

    return 0;
}