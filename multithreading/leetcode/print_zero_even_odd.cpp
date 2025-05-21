#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

void printNumber(int x) { cout << x; };

class ZeroEvenOdd
{
private:
    int n;
    int x;
    mutex m;
    condition_variable cv;

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
        x = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        while (x <= 2 * n)
        {
            unique_lock<mutex> ulck(m);
            cv.wait(ulck, [this]()
                    { return x % 2 == 1; });
            if (x <= 2 * n)
                printNumber(0);
            x++;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber)
    {
        while (x <= 2 * n)
        {
            unique_lock<mutex> ulck(m);
            cv.wait(ulck, [this]()
                    { return x % 4 == 0 ? true : false; });
            if (x <= 2 * n)
                printNumber(x / 2);
            x++;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber)
    {

        while (x <= 2 * n)
        {
            unique_lock<mutex> ulck(m);
            cv.wait(ulck, [this]()
                    { return (x % 2 == 0 && x % 4 != 0) ? true : false; });
            if (x <= 2 * n)
                printNumber(x / 2);
            x++;
            cv.notify_all();
        }
    }
};

int main()
{

    for (int i = 1; i <= 20; i += 1)
    {
        ZeroEvenOdd obj(i);
        thread t1(&ZeroEvenOdd::zero, &obj, printNumber);
        thread t2(&ZeroEvenOdd::even, &obj, printNumber);
        thread t3(&ZeroEvenOdd::odd, &obj, printNumber);
        t1.join();
        t2.join();
        t3.join();
        cout << endl;
    }

    return 0;
}