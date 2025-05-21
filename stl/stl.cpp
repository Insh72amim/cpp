#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> s = {1, 2, 3, 4, 5};        // list of elements, unique -> Java HashSet
    set<int> ss = {1, 2, 3, 4, 5};                 // list of elements, unique, sorted -> Java TreeSet
    unordered_multiset<int> ums = {1, 2, 3, 4, 5}; // list of elements, just -> Not available in Java | Guava Library
    multiset<int> mss = {1, 2, 3, 4, 5};           // list of elements, sorted -> Not available in Java | Guava Library

    unordered_map<int, int> ump = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}}; // list of key and value, unique key -> Java HashMap
    map<int, int> mp = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};            // list of key and value, unique key, , sorted by key -> Java TreeMap
    unordered_multimap<int, int> umm = {{1, 1}, {2, 2}, {3, 3}};            // list of key and value, just -> Not available in Java | Guava Library
    multimap<int, int> mm = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};       // list of key and value, sorted by key ->  Not available in Java | Guava Library

    vector<int> arr = {1, 2, 3, 4, 5}; // vector -> Java ArrayList
    list<int> l = {1, 2, 3, 4, 5};     // list   -> Java LinkedList (although technical difference is there)

    stack<int> st; // stack      -> Deque (Stack is legacy)
    deque<int> d;  // deque      -> ArrayDeque
    queue<int> q;  // queue      -> Queue

    priority_queue<int> pq;                             // max heap   -> PriorityQueue (with comparator)
    priority_queue<int, vector<int>, greater<int>> pq2; // min heap   -> PriorityQueue (default min heap)

    list<int>::iterator it = l.begin();

    return 0;
}