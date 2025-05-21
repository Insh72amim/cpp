#include <iostream>
#include <thread>
#include <mutex>

int amount = 0;
std::mutex m;

void addMoney()
{
    m.lock();
    amount++;
    m.unlock();
}

int main()
{
    std::thread t1(addMoney);
    std::thread t2(addMoney);
    std::thread t3(addMoney);
    std::thread t4(addMoney);
    std::thread t5(addMoney);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    std::cout << amount << std::endl;
    return 0;
}
