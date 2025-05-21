#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std;

void waitForMe(std::promise<int> &&somePromise)
{
    this_thread::sleep_for(chrono::seconds(3));
    somePromise.set_value(5);
}

int main()
{
    std::promise<int> myPromise;
    std::future<int> myIntFut = myPromise.get_future();
    thread t(waitForMe, std::move(myPromise));
    cout << myIntFut.get() << endl;
    t.join();
    return 0;
}
