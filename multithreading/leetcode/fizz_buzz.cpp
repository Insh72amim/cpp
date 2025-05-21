#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <future>
using namespace std;

void printFizz() { cout << "fizz\n"; };
void printBuzz() { cout << "buzz\n"; };
void printFizzBuzz() { cout << "fizzbuzz\n"; };
void printNumber(int z) { cout << z << endl; };

class FizzBuzz
{
private:
    int n;
    int i;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) : i(1)
    {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        while (i <= n)
        {
            unique_lock<mutex> lck(m);
            cv.wait(lck, [this]()
                    { return i % 3 == 0 && i % 5 != 0 || i > n; });
            if (i <= n)
                printFizz();
            i++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        while (i <= n)
        {

            unique_lock<mutex> lck(m);
            cv.wait(lck, [this]()
                    { return i % 3 != 0 && i % 5 == 0 || i > n; });
            if (i <= n)
                printBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        while (i <= n)
        {

            unique_lock<mutex> lck(m);
            cv.wait(lck, [this]()
                    { return i % 3 == 0 && i % 5 == 0 || i > n; });
            if (i <= n)
                printFizzBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        while (i <= n)
        {
            unique_lock<mutex> lck(m);
            cv.wait(lck, [this]()
                    { return i % 3 != 0 && i % 5 != 0 || i > n; });
            if (i <= n)
                printNumber(i);
            i++;
            cv.notify_all();
        }
    }
};

int main()
{
    FizzBuzz foo(15);
    thread t1(&FizzBuzz::fizzbuzz, &foo, printFizzBuzz);
    thread t2(&FizzBuzz::buzz, &foo, printBuzz);
    thread t3(&FizzBuzz::fizz, &foo, printFizz);
    thread t4(&FizzBuzz::number, &foo, printNumber);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}