#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

std::mutex m;
std::condition_variable cv;
long balance = 0;

void addMoney(int money)
{
    std::unique_lock<mutex> lg(m);
    balance += money;
    cout << "Current Balance : " << balance << endl;
    cv.notify_one();
}

void withdrawMoney(int money)
{
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, []()
            { return balance != 0 ? true : false; });
    if (balance >= money)
    {
        balance -= money;
        cout << "Amount deducted : " << money << endl;
    }
    else
        cout << "Insufficient Balance\n";

    cout << "Your Current Balance is : " << balance << endl;
}

int main()
{
    std::thread t2(withdrawMoney, 500);
    std::thread t1(addMoney, 500);

    t1.join();
    t2.join();

    return 0;
}
