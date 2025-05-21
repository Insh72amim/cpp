#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <future>
using namespace std;

void printFirst() { cout << "first\n"; };
void printSecond() { cout << "second\n"; };
void printThird() { cout << "third\n"; };

// using mutex and conditional variables

class FooM
{
    int order = 0;
    std::mutex m;
    std::condition_variable cv;

public:
    FooM()
    {
    }

    void first(function<void()> printFirst)
    {
        std::unique_lock<std::mutex> lck(m);
        cv.wait(lck, [this]()
                { return order == 0 ? true : false; });
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        order++;
        cv.notify_all();
    }

    void second(function<void()> printSecond)
    {
        std::unique_lock<std::mutex> lck(m);
        cv.wait(lck, [this]()
                { return order == 1 ? true : false; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        order++;
        cv.notify_all();
    }

    void third(function<void()> printThird)
    {
        std::unique_lock<std::mutex> lck(m);
        cv.wait(lck, [this]()
                { return order == 2 ? true : false; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        order++;
        cv.notify_all();
    }
};

// using promise

class Foo
{
    std::promise<void> p1;
    std::promise<void> p2;

public:
    Foo()
    {
    }

    void first(function<void()> printFirst)
    {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        p1.set_value();
    }

    void second(function<void()> printSecond)
    {
        p1.get_future().wait();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        p2.set_value();
    }

    void third(function<void()> printThird)
    {
        p2.get_future().wait();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

int main()
{
    Foo foo;
    thread t3(&Foo::third, &foo, printThird);
    thread t2(&Foo::second, &foo, printSecond);
    thread t1(&Foo::first, &foo, printFirst);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}