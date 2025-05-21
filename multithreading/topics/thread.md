# Threads in C++

## Header Thread

Header that declares the `thread` class and the `this_thread` namespace

## Class `thread`

Class to represent individual threads of execution.

A thread of execution is a sequence of instructions that can be executed concurrently with other such sequences in multithreading environments, while sharing a same address space.

An initialized thread object represents an active thread of execution; Such a thread object is joinable, and has a unique thread id.

A default-constructed (non-initialized) thread object is not joinable, and its thread id is common for all non-joinable threads.

A joinable thread becomes not joinable if moved from, or if either join or detach are called on them.

### Member types [Public Member Type]

- id
- native_handle_type

### Member functions [Public Member Functions]

- (constructor) Construct thread
- (destructor) Thread destructor

- operator= : Move-assign thread
- get_id : Get thread id
- joinable : Check if joinable
- join : Join thread
- detach : Detach thread
- swap : Swap threads
- native_handle : Get native handle

## Namespace `this_thread`

This namespace groups a set of functions that access the current thread.

- get_id : Get thread id (function)
- yield : Yield to other threads (function)
- sleep_until : Sleep until time point (function)
- sleep_for Sleep : for time span (function)
