#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std;

int waitForMe()
{
    this_thread::sleep_for(chrono::seconds(3));
    return 5;
}

int main()
{

    std::future<int> myIntFut = std::async(std::launch::deferred, waitForMe);
    cout << myIntFut.get() << endl;
    return 0;
}
