# unique_lock In C++ programming language.

Few important points to remember about the unique_lock is as follows:

1. The class unique_lock is a mutex ownership wrapper.
2. It Allows:
   a. Can Have Different Locking Strategies
   b. time-constrained attempts at locking (try_lock_for, try_lock_until)
   c. recursive locking
   d. transfer of lock ownership (move not copy)
   e. condition variables. (See this in coming videos)

## Locking Strategies

TYPE EFFECTS(S)

1. defer_lock do not acquire ownership of the mutex.
2. try_to_lock try to acquire ownership of the mutex without blocking.
3. adopt_lock assume the calling thread already has ownership of the mutex.
