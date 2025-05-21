#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
typedef long long int ull;

void fun(int x)
{
    while (x--)
        cout << x << endl;
}

int main()
{

    thread t(fun, 10);
    t.detach();
    return 0;
}