# Mutex: Mutual Exclusion

## RACE CONDITION:

0. Race condition is a situation where two or more threads/process happens to change a common data at the same time.
1. If there is a race condition then we have to protect it and the protected section is called critical section/region.

## MUTEX:

0. Mutex is used to avoid race condition.
1. We use lock() , unlock() on mutex to avoid race condition.
