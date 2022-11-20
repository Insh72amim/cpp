#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

class point
{
public:
    int x, y;
    point(int x, int y)
    {
        x = this->x;
        y = this->y;
    }
};

bool compx(point *p1, point *p2)
{
    return p1->x < p2->x;
}

bool compy(point *p1, point *p2)
{
    return p2->x < p2->y;
}

class Solution
{
private:
    int find(vector<int> &link, int x)
    {
        while (x != link[x])
            return find(link, link[x]);
        return x;
    }

    void unite(vector<int> &link, int a, int b)
    {
        a = find(link, a);
        b = find(link, b);
        link[a] = b;
    }

    bool same(vector<int> &link, int a, int b)
    {
        return find(link, a) == find(link, b);
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<point *> v;
        for (auto u : stones)
        {
            point *p = new point(u[0], u[1]);
            v.push_back(p);
        }

        sort(v.begin(), v.end(), compx);

        for (int i = 0; i < n; i++)
        {
        }
    }
};

int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, pair<int, int>>> edges;
    int x, y, z;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> z;
        edges.push_back({z, {x, y}});
    }

    sort(edges.begin(), edges.end());

    vector<int> link(v);
    for (int i = 0; i < v; i++)
        link[i] = i;

    int w, a, b;
    int mst = 0;
    for (auto u : edges)
    {
        w = u.fi, a = u.se.fi, b = u.se.se;
        if (!same(link, a, b))
        {
            unite(link, a, b);
            mst += w;
        }
    }

    cout << mst;

    return 0;
}