#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &ans)
{
    vector<vector<int>> v = {
        {1, 2},
        {1, 3},
        {2, 11},
        {3, 9},
        {4, 13},
        {1, 4},
        {2, 7},
        {2, 5},
    };
    /*
        {1, 3},
        {1, 2},
        {2, 11},
        {2, 7},
        {2, 5},
        {3, 4},
        {4, 13},
    */
}

int main()
{
    int tcase;
    cin >> tcase;
    vector<int> ans;
    while (tcase--)
        solve(ans);
    printG(ans);
    return 0;
}