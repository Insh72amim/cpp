// This code contains standard functions used in cp
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sum(a) (accumulate((a).begin(), (a).end(), 0ll))
#define mine(a) (*min_element((a).begin(), (a).end()))
#define maxe(a) (*max_element((a).begin(), (a).end()))
#define mini(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define nl (cout << "\n")

using namespace std;
typedef long long ll;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
bool isSubSequence(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
        if (str1[j] == str2[i])
            j++;
    return (j == m);
}
ll power(ll x, ll n)
{
    if (n == 0)
        return 1;
    ll tpow = power(x, n / 2);
    tpow *= tpow;
    if (n & 1)
        tpow *= x;
    return tpow;
}
void seive()
{
    int n;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}
int lower_bound(int arr[], int N, int X)
{
    int mid, l = 0, h = N;
    while (l < h)
    {
        mid = l + (h - l) / 2;
        if (X <= arr[mid])
            h = mid;
        else
            l = mid + 1;
    }
    if (l < N && arr[l] < X)
        l++;
    return l;
}
int upper_bound(int arr[], int N, int X)
{
    int mid, l = 0, h = N;
    while (l < h)
    {
        mid = l + (h - l) / 2;
        if (X >= arr[mid])
            l = mid + 1;
        else
            h = mid;
    }
    if (l < N && arr[l] <= X)
        l++;
    return l;
}
void solve()
{
}

int main()
{
    int tcase;
    cin >> tcase;
    tcase = 1;
    while (tcase--)
        solve();
    return 0;
}
