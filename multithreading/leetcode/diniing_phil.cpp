#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

class DiningPhilosophers
{
    mutex m;

public:
    DiningPhilosophers()
    {
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork)
    {
        m.lock();
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        m.unlock();
    }
};

int main()
{

    return 0;
}