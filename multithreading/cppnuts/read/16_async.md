# TOPIC: std::async

NOTES:

1. It runs a function asynchronously (potentially in a new thread) and returns a std::future that
   will hold the result.
2. There are three launch policies for creating task:
   a. std::launch::async
   b. std::launch::deffered
   c. std::launch::async | std::launch::async

## HOW IT WORKS:

1. It automatically creates a thread (Or picks from internal thread pool) and a promise object for us.
2. Then passes the std::promise object to thread function and returns the associated std::future object.
3. When our passed argument function exits then its value will be set in this promise object,
   so eventually return value will be available in std::future object.

SIDE NOTES:

1. We can send functor and lambda function as callback to std::async, it will work the same.
