
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> tsort;
    void dfs(unordered_map<int, vector<int>> &adj, vector<int> &vis, int i)
    {
        if (vis[i])
            return;
        vis[i] = 1;
        for (auto u : adj[i])
        {
            dfs(adj, vis, u);
        }
        tsort.push_back(i);
    }

    bool detectCycle(unordered_map<int, vector<int>> &adj, vector<int> &vis, vector<int> &rec, int i)
    {
        if (vis[i] == 0)
        {
            vis[i] = true;
            rec[i] = true;
            for (auto u : adj[i])
            {
                if (!vis[u] && detectCycle(adj, vis, rec, u))
                    return true;
                else if (rec[u])
                    return true;
            }
        }
        return rec[i] = false;
    }

public:
    string alienOrder(vector<string> &words)
    {
        if (words.size() == 1)
        {
            string temp = words[0];
            reverse(temp.begin(), temp.end());
            return temp;
        }

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < words.size() - 1; i++)
        {
            string w1 = words[i], w2 = words[i + 1];
            int l1 = words[i].length();
            int l2 = words[i + 1].length();
            for (auto u : words[i])
                adj[u - 'a'];
            for (auto u : words[i + 1])
                adj[u - 'a'];
            bool found = false;
            for (int l = 0; l < min(l1, l2); l++)
            {
                int a = words[i][l] - 'a';
                int b = words[i + 1][l] - 'a';
                if (a != b)
                {
                    adj[a].push_back(b);
                    found = true;
                    break;
                }
            }
            if (!found && w1.size() > w2.size())
                return "";
        }

        vector<int> vis(26, 0), rec(26, 0);
        for (auto u : adj)
        {
            if (vis[u.first] == 0 && detectCycle(adj, vis, rec, u.first))
            {
                return "";
            };
        }

        fill(vis.begin(), vis.end(), 0);
        for (auto it = adj.begin(); it != adj.end(); it++)
        {
            if (!vis[it->first])
            {
                dfs(adj, vis, it->first);
            }
        }

        reverse(tsort.begin(), tsort.end());
        string res = "";
        for (auto u : tsort)
            res.push_back(char('a' + u));
        return res;
    }
};
int main()
{
    string str = "Hello, World!";
    reverse(str.begin(), str.end());
    set<int> ms;
    ms.insert(4);
    ms.insert(3);
    ms.insert(2);
    ms.insert(5);
    ms.insert(1);
    for (auto it : ms)
        cout << it << endl;
    ms.erase(ms.find(4));
    for (auto it : ms)
        cout << it << endl;
    return 0;
}
