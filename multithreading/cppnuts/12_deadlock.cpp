#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex m1;
mutex m2;

void thread1()
{
    m1.lock();
    // std::this_thread::sleep_for(chrono::seconds(1));
    m2.lock();
    cout << "This is thread 1 running\n";
    m2.unlock();
    m1.unlock();
}

void thread2()
{
    m2.lock();
    // std::this_thread::sleep_for(chrono::seconds(1));
    m1.lock();
    cout << "This is thread 2 running\n";
    m1.unlock();
    m2.unlock();
}

int main()
{
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}