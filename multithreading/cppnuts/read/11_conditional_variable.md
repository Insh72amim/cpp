# "Condition Variable In C++ Threading"

Few important points to remember while using "condition variables" are as follows

1. Condition variables allow us to synchronise threads via notifications.
   a. notify_one();
   b. notify_all();
2. You need mutex to use condition variable
3. Condition variable is used to synchronise two or more threads.
4. Best use case of condition variable is Producer/Consumer problem.
5. Condition variables can be used for two purposes:
   a. Notify other threads
   b. Wait for some condition
