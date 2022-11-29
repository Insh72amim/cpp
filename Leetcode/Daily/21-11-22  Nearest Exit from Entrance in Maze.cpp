#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &e)
    {
        int n = maze.size(), m = maze[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        q.push({e[0], e[1]});
        int val = 0;
        while (!q.empty())
        {
            for (int i = 0, n = q.size(); i < n; i++)
            {
                int a = q.front().first, b = q.front().second;
                q.pop();
                maze[a][b] = '+';
                if ((a == 0 || b == 0 || a == n - 1 || b == m - 1) && !(a == e[0] && b == e[1]))
                    return val;
                for (auto p : dir)
                {
                    int x = a + p.first, y = b + p.second;
                    if (x >= 0 && y >= 0 && x < n && y < m && maze[x][y] == '.')
                        q.push({x, y});
                }
            }
            val++;
        }
        return -1;
    }
};

int main()
{
    return 0;
}