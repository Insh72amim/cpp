#include <iostream> // std::cout
#include <thread>   // std::thread, std::this_thread::yield
#include <atomic>   // std::atomic

// Yield to other threads

// The calling thread yields, offering the implementation the opportunity to reschedule.

// This function shall be called when a thread waits for other threads to advance without blocking.

std::atomic<bool> ready(false);

void count1m(int id)
{
    while (!ready)
    { // wait until main() sets ready...
        std::this_thread::yield();
    }
    for (volatile int i = 0; i < 1000000; ++i)
    {
    }
    std::cout << id;
}

int main()
{
    std::thread threads[10];
    std::cout << "race of 10 threads that count to 1 million:\n";
    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(count1m, i);
    ready = true; // go!
    for (auto &th : threads)
        th.join();
    std::cout << '\n';

    return 0;
}