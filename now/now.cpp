#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long long mae(vector<int> &arr)
    {
        long long cost = 0;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int m = arr[n / 2];
        for (int i = 0; i < n; i++)
            cost += abs(arr[i] - m);

        if (n % 2 == 0)
        {
            long long temp = 0;
            m = arr[n / 2 - 1];
            for (int i = 0; i < n; i++)
                temp += abs(arr[i] - m);
            cost = min(cost, temp);
        }

        return cost;
    }
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

public:
    long long makeSubKSumEqual(vector<int> &arr, int k)
    {
        int n = arr.size();
        long long res = 0;
        unordered_map<int, vector<int>> um;
        for (int i = 0; i < arr.size(); i++)
            um[i % k].push_back(arr[i]);
        vector<int> vt(arr.begin(), arr.end());
        long long alleq = mae(vt);
        if (n % k != 0)
            return min(alleq, makeSubKSumEqual(arr, gcd(n, k)));
        for (auto u : um)
        {
            res += mae(u.second);
        }
        res = min(alleq, res);
        return res;
    }
};

class Solution
{
public:
    int ways(vector<string> &pizza, int k)
    {
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(k, vector<vector<int>>(m, vector<int>(n, -1)));
        vector<vector<int>> preSum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        for (int r = m - 1; r >= 0; r--)
            for (int c = n - 1; c >= 0; c--)
                preSum[r][c] = preSum[r][c + 1] + preSum[r + 1][c] - preSum[r + 1][c + 1] + (pizza[r][c] == 'A');

        return dfs(m, n, k - 1, 0, 0, dp, preSum);
    }

    int dfs(int m, int n, int k, int r, int c, vector<vector<vector<int>>> &dp, vector<vector<int>> &preSum)
    {
        if (preSum[r][c] == 0)
            return 0;
        if (k == 0)
            return 1;
        if (dp[k][r][c] != -1)
            return dp[k][r][c];
        int ans = 0;

        for (int nr = r + 1; nr < m; nr++)
            if (preSum[r][c] - preSum[nr][c] > 0)
                ans = (ans + dfs(m, n, k - 1, nr, c, dp, preSum)) % 1000000007;

        for (int nc = c + 1; nc < n; nc++)
            if (preSum[r][c] - preSum[r][nc] > 0)
                ans = (ans + dfs(m, n, k - 1, r, nc, dp, preSum)) % 1000000007;
        return dp[k][r][c] = ans;
    }
};

int main()
{
    string S = "abacaba";
    int N = S.length();

    return 0;
}