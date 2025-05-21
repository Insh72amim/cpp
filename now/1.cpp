#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int result(int m, int r)
{
  if (r > m)
    return 0;
  long res = 1;
  for (int i = m - r + 1; i <= m; i++)
  {
    res = (res * i) % mod;
  }
  return (int)res;
}

int countWays(int m, int g, vector<int> &from, vector<int> &to)
{
  vector<vector<int>> adj(g);
  for (int i = 0; i < from.size(); i++)
  {
    adj[from[i] - 1].push_back(to[i] - 1);
    adj[to[i] - 1].push_back(from[i] - 1);
  }
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

  return 0;
}
