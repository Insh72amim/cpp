#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;
ll mod = 1e9 + 7;
ll i, j, k;

int main()
{
    ll num, n, k;
    vector<pair<ll, ll>> v;

    ifstream input("input.txt");
    i = 0;
    while (input >> num)
    {
        if (i == 0)
            n = num;
        else if (i == 1)
            k = num;
        else
            v.pb({num, i - 1});
        i++;
    }
    input.close();

    sort(all(v));
    reverse(all(v));

    ofstream output("output.txt");
    output << v[k - 1].fi << "\n";
    for (i = 0; i < k; i++)
        output << v[i].se;

    output.close();

    return 0;
}