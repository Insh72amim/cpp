#include <bits/stdc++.h>
using namespace std;

int countWays(int m, int g, vector<int> &from, vector<int> &to)
{
    int mod = 1e9 + 7;

    vector<vector<int>> adj(g);
    for (int i = 0; i < from.size(); i++)
    {
        adj[from[i] - 1].push_back(to[i] - 1);
        adj[to[i] - 1].push_back(from[i] - 1);
    }

    vector<int> mon(g, 0);
    vector<bool> vis(g, false);
    queue<pair<int, int>> q;
    q.push({0, -1});

    long long total = 1;

    while (!q.empty())
    {
        for (int i = 0, n = q.size(); i < n; i++)
        {
            pair<int, int> front = q.front();
            q.pop();
            int curr = front.first, par = front.second;

            if (vis[curr])
                continue;
            vis[curr] = true;

            if (par == -1)
                total = (total * m) % mod;
            else
            {
                mon[par]++;
                if (m > mon[par])
                    total = (total * (m - mon[par])) % mod;
                else
                    return 0;
            }

            for (auto u : adj[curr])
            {
                if (!vis[u])
                {
                    q.push({u, curr});
                    mon[u]++;
                }
            }
        }
    }

    return total;
}

int main()
{
    int m = 12;
    int g = 13;
    vector<int> from = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};
    vector<int> to = {
        2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    cout << countWays(m, g, from, to) << endl;

    // int m = 4;
    // int g = 3;
    // vector<int> from = {1, 1};
    // vector<int> to = {
    //     2,
    //     3,
    // };
    // cout << countWays(m, g, from, to) << endl;

    // int m = 3;
    // int g = 4;
    // vector<int> from = {1, 2, 3};
    // vector<int> to = {
    //     2,
    //     3,
    //     4};
    // cout << countWays(m, g, from, to) << endl;

    // int m = 4;
    // int g = 4;
    // vector<int> from = {1, 1, 2};
    // vector<int> to = {
    //     2,
    //     3,
    //     4};

    // cout << countWays(m, g, from, to) << endl;

    return 0;
}
