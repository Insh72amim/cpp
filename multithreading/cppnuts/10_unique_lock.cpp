#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex m1;
int buffer = 0;

// EXAMPLE: 1

void task(const char *threadNumber, int loopFor)
{
    std::unique_lock<mutex> lock(m1); // Automatically calls lock on mutex m1
    for (int i = 0; i < loopFor; ++i)
    {
        buffer++;
        cout << threadNumber << buffer << endl;
    }
}

int main()
{
    thread t1(task, "T1 ", 10);
    thread t2(task, "T2 ", 10);
    t1.join();
    t2.join();
    return 0;
}

// EXAMPLE: 2

void task(const char *threadNumber, int loopFor)
{
    std::unique_lock<mutex> lock(m1, std::defer_lock); // Does not call lock on mutex m1, because used defer_lock
    lock.lock();                                       // But then we will have to explicitly tell to lock when ever we want to lock mutex m1.
    for (int i = 0; i < loopFor; ++i)
    {
        buffer++;
        cout << threadNumber << buffer << endl;
    }
    // lock.unlock(); is not needed as it will be unlocked in destructor of unique_lock.
}

int main()
{
    thread t1(task, "T1 ", 10);
    thread t2(task, "T2 ", 10);
    t1.join();
    t2.join();
    return 0;
}
