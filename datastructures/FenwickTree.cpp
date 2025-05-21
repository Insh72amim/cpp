#include <bits/stdc++.h>
using namespace std;

class FenwickTree
{
    vector<int> arr;
    int n;

public:
    FenwickTree(vector<int> arr)
    {
        this->n = arr.size();
        this->arr = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++)
            add(i, arr[i - 1]);
    }

    void add(int i, int val)
    {
        while (i <= n)
        {
            arr[i] += val;
            i += i & -i;
        }
    }

    int sum(int i)
    {
        int res = 0;
        while (i > 0)
        {
            res += arr[i];
            i -= i & -i;
        }
        return res;
    }

    void print()
    {
        for (auto u : arr)
        {
            cout << u << " ";
        }
        cout << endl;
    }
};

int main()
{
    FenwickTree *ft = new FenwickTree(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    ft->print();
    cout << ft->sum(10) << endl;
    ft->add(1, 10);
    ft->add(2, 10);
    ft->add(3, 10);
    ft->add(4, 10);
    ft->add(5, 10);
    ft->add(6, 10);
    ft->add(7, 10);
    ft->add(8, 10);
    ft->add(9, 10);
    ft->add(10, 10);
    cout << ft->sum(10) << endl;
}