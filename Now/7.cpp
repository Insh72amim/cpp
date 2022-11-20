#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll area(ll x1, ll y1, ll x2, ll y2, ll n)
{
    ll l1, b1, l2, b2, ar1, ar2, ar;
    if (x1 == x2)
    {
        ar = abs(y2 - y1) * max(x1, n - 1 - x1);
    }
    else if (y1 == y2)
    {
        ar = abs(x2 - x1) * max(y1, n - 1 - y1);
    }
    else
    {
        l1 = max(max(x1, n - 1 - x1), max(x2, n - 1 - x2));
        b1 = abs(y2 - y1);
        ar1 = l1 * b1;
        l2 = abs(x2 - x1);
        b2 = max(max(y1, n - 1 - y1), max(y2, n - 1 - y2));
        ar2 = l2 * b2;
        ar = max(ar1, ar2);
    }
    return ar;
}

int main()
{
    ll t, i, j, k, x, y, z, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string s[n + 1];
        for (i = 0; i < n; ++i)
            cin >> s[i];

        vector<pair<int, int>> v;
        for (i = 0; i <= 9; ++i)
        {
            for (j = 0; j < n; ++j)
                for (k = 0; k < n; ++k)
                    if (s[j][k] - 48 == i)
                    {
                        v.push_back(make_pair(j, k));
                        break;
                    }

            for (j = n - 1; j >= 0; --j)
                for (k = 0; k < n; ++k)
                    if (s[j][k] - 48 == i)
                    {
                        v.push_back(make_pair(j, k));
                        break;
                    }
            for (j = 0; j < n; ++j)
                for (k = n - 1; k >= 0; --k)
                    if (s[j][k] - 48 == i)
                    {
                        v.push_back(make_pair(j, k));
                        break;
                    }
            for (j = n - 1; j >= 0; --j)
                for (k = n - 1; k >= 0; --k)
                    if (s[j][k] - 48 == i)
                    {
                        v.push_back(make_pair(j, k));
                        break;
                    }
            if (v.size() < 2)
            {
                cout << 0 << " ";
                v.clear();
                continue;
            }
            z = INT_MIN;
            for (j = 0; j < v.size(); ++j)
            {
                for (k = j + 1; k < v.size(); ++k)
                {
                    y = area(v[j].first, v[j].second, v[k].first, v[k].second, n);
                    z = max(y, z);
                }
            }
            cout << z << " ";
            v.clear();
        }
        cout << "\n";
    }
    return 0;
}