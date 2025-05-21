# Atomic in C++

## Header Atomic

Atomic types are types that encapsulate a value whose access is guaranteed to not cause data races and can be used to synchronize memory accesses among different threads.

This header declares two C++ classes, **atomic** and **atomic_flag**, that implement all the features of atomic types in self-contained classes. The header also declares an entire set of C-style types and functions compatible with the atomic support in C.

## Classes Atomic

atomic Atomic (class template)
atomic_flag Atomic flag (class)

## Types

memory_order Memory order (enum)

## Functions

kill_dependency Kill dependency (function)
atomic_thread_fence Thread fence (function)
atomic_signal_fence Signal fence (function)

Functions for atomic objects (C-style)
atomic_is_lock_free Is lock-free (function)
atomic_init Initialize atomic object (function)
atomic_store Modify contained value (function)
atomic_store_explicit Modify contained value (explicit memory order) (function)
atomic_load Read contained value (function)
atomic_load_explicit Read contained value (explicit memory order) (function)
atomic_exchange Read and modify contained value (function)
atomic_exchange_explicit Read and modify contained value (explicit memory order) (function)
atomic_compare_exchange_weak Compare and exchange contained value (weak) (function)
atomic_compare_exchange_weak_explicit Compare and exchange contained value (weak, explicit) (function)
atomic_compare_exchange_strong Compare and exchange contained value (strong) (function)
atomic_compare_exchange_strong_explicit Compare and exchange contained value (strong, explicit) (function)
atomic_fetch_add Add to contained value (function)
atomic_fetch_add_explicit Add to contained value (explicit memory order) (function)
atomic_fetch_sub Subtract from contained value (function)
atomic_fetch_sub_explicit Subtract from contained value (explicit memory order) (function)
atomic_fetch_and Apply bitwise AND to contained value (function)
atomic_fetch_and_explicit Apply bitwise AND to contained value (explicit memory order) (function)
atomic_fetch_or Apply bitwise OR to contained value (function)
atomic_fetch_or_explicit Apply bitwise OR to contained value (explicit memory order) (function)
atomic_fetch_xor Apply bitwise XOR to contained value (function)
atomic_fetch_xor_explicit Apply bitwise XOR to contained value (explicit memory order) (function)

Functions for atomic flags (C-style)
atomic_flag_test_and_set Test and set atomic flag (function)
atomic_flag_test_and_set_explicit Test and set atomic flag (explicit memory order) (function)
atomic_flag_clear Clear atomic flag (function)
atomic_flag_clear_explicit Clear atomic flag (explicit memory order) (function)

Macro functions
ATOMIC_VAR_INIT Initialization of atomic variable (macro)
ATOMIC_FLAG_INIT Initialization of atomic flag (macro)

Macro constants
macro relative to types defined as
ATOMIC_BOOL_LOCK_FREE bool 0 if the types are never lock-free.
1 it the types are sometimes lock-free.
2 if the types are always lock-free.

Consistent with the value returned by atomic::is_lock_free.
ATOMIC_CHAR_LOCK_FREE char
signed char
unsigned char
ATOMIC_SHORT_LOCK_FREE short
unsigned short
ATOMIC_INT_LOCK_FREE int
unsigned int
ATOMIC_LONG_LOCK_FREE long
unsigned long
ATOMIC_LLONG_LOCK_FREE long long
unsigned long long
ATOMIC_WCHAR_T_LOCK_FREE wchar_t
ATOMIC_CHAR16_T_LOCK_FREE char16_t
ATOMIC_CHAR32_T_LOCK_FREE char32_t
ATOMIC_POINTER_LOCK_FREE U\*
(for any type U)
