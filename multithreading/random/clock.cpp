#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
typedef long long int ull;

int main()
{

    auto startTime = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
    std::cout << duration.count() / 1000000;
    return 0;
}