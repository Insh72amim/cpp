#include <iostream> // std::cout
#include <iomanip>  // std::put_time
#include <thread>   // std::this_thread::sleep_until
#include <chrono>   // std::chrono::system_clock
#include <ctime>    // std::time_t, std::tm, std::localtime, std::mktime

// Sleep until time point. Blocks the calling thread until abs_time.
// The execution of the current thread is stopped until at least abs_time, while other threads may continue to advance.

// Parameters : abs_time
// A point in time when the calling thread shall resume its execution.
// Note that multi-threading management operations may cause certain delays beyond this.
// time_point is an object that represents a specific absolute time.

int main()
{
    using std::chrono::system_clock;
    std::time_t tt = system_clock::to_time_t(system_clock::now());

    struct std::tm *ptm = std::localtime(&tt);
    std::cout << "Current time: " << std::put_time(ptm, "%X") << '\n';

    std::cout << "Waiting for the next minute to begin...\n";
    ++ptm->tm_min;
    ptm->tm_sec = 0;
    std::this_thread::sleep_until(system_clock::from_time_t(mktime(ptm)));

    std::cout << std::put_time(ptm, "%X") << " reached!\n";

    return 0;
}