#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <future>
using namespace std;

void printFirst() { cout << "first\n"; };
void printSecond() { cout << "second\n"; };
void printThird() { cout << "third\n"; };

class FooBar
{
private:
    int n;
    int cnt;
    mutex m;
    condition_variable cv;

public:
    FooBar(int n)
    {
        this->n = n;
        cnt = 0;
    }

    void foo(function<void()> printFoo)
    {

        for (int i = 0; i < n; i++)
        {
            std::unique_lock lck(m);
            cv.wait(lck, [this]()
                    { return cnt % 2 == 0 ? true : false; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            cnt++;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar)
    {

        for (int i = 0; i < n; i++)
        {
            cout << "D\n";
            std::unique_lock lck(m);
            cv.wait(lck, [this]()
                    { return cnt % 2 == 1 ? true : false; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            cnt++;
            cv.notify_one();
        }
    }
};

int main()
{
    // Foo foo;
    // thread t3(&Foo::third, &foo, printThird);
    // thread t2(&Foo::second, &foo, printSecond);
    // thread t1(&Foo::first, &foo, printFirst);
    // t1.join();
    // t2.join();
    // t3.join();
    return 0;
}