
#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    vector<int> link;
    vector<int> size;

public:
    UnionFind(int n)
    {
        link.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            link[i] = i;
    }
    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (size[a] < size[b])
            swap(a, b);
        link[b] = a;
        size[a] += size[b];
    }
    int find(int a)
    {
        return link[a] == a ? a : find(link[a]);
    }
    bool same(int a, int b)
    {
        return find(a) == find(b);
    }
};