#include <bits/stdc++.h>
using namespace std;

class LRUCache
{

    class DLL
    {
    public:
        int val;
        DLL *next, *prev;
        DLL(int x)
        {
            val = x;
            prev = next = nullptr;
        }
    };

    unordered_map<int, int> um;
    unordered_map<int, DLL *> keyAddress;
    DLL *start, *end;
    int cap;
    int llsize;

    void addOneNodeLL(int key)
    {
        DLL *newNode = new DLL(key);
        end->next = newNode;
        newNode->prev = end;
        end = end->next;
        llsize++;
    }

    void removeOldNodeLL()
    {
        if (start->next)
        {
            DLL *newOldNode = start->next->next;
            keyAddress.erase(start->next->val);
            um.erase(start->next->val);
            delete start->next;
            start->next = newOldNode;
            newOldNode->prev = start;
            llsize--;
        }
    }

    void removeOneNodeLL(int key)
    {
        if (keyAddress.find(key) != keyAddress.end())
        {
            DLL *curr = keyAddress[key];
            DLL *pNode = curr->prev;
            DLL *nNode = curr->next;
            pNode->next = nNode;
            nNode->prev = pNode;
            delete curr;
            llsize--;
        }
    }

    void movetoEnd(int key)
    {
        if (keyAddress.find(key) != keyAddress.end())
        {
            removeOneNodeLL(key);
            addOneNodeLL(key);
        }
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        llsize = 0;
        start = new DLL(-1);
        end = start;
    }

    int get(int key)
    {
        if (um.find(key) != um.end())
        {
            movetoEnd(key);
            return um[key];
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (um.find(key) != um.end())
            removeOneNodeLL(key);
        if (llsize >= cap)
            removeOldNodeLL();
        addOneNodeLL(key);
        um[key] = value;
        keyAddress[key] = end;
    }

    void print()
    {
        DLL *curr = start;
        while (curr)
            cout << curr->val << " ", curr = curr->next;
        cout << endl;
        cout << endl;
        for (auto u : um)
            cout << u.first << " " << u.second << endl;
        cout << endl;
        cout << endl;
        for (auto u : keyAddress)
            cout << u.first << " " << u.second->val << endl;
    }
};

int main()
{
    LRUCache *cache = new LRUCache(1);
    // cache->put(3, 3);
    // cache->put(5, 5);
    // cache->put(1, 1);
    // cache->put(4, 4);
    // cache->put(7, 7);
    // cache->put(8, 8);
    // cache->put(4, 4);
    // cache->print();
    cache->put(2, 1);
    cache->get(2);
}