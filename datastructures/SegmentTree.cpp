#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int> arr)
    {
        this->n = arr.size();
        tree.resize(4 * n);
        buildSegmentTree(0, 0, n - 1, arr);
    }

private:
    void buildSegmentTree(int node, int start, int end, vector<int> &arr)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        buildSegmentTree(2 * node + 1, start, mid, arr);
        buildSegmentTree(2 * node + 2, mid + 1, end, arr);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int queryUtil(int node, int start, int end, int l, int r)
    {
        if (l > r)
            return 0;
        if (start == l && end == r)
            return tree[node];
        int mid = (start + end) / 2;
        int leftSum = queryUtil(2 * node + 1, start, mid, l, min(mid, r));
        int rightSum = queryUtil(2 * node + 2, mid + 1, end, max(l, mid + 1), r);
        return leftSum + rightSum;
    }

    void updateUtil(int node, int start, int end, int i, int val)
    {
        if (start == end)
        {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (i <= mid)
            updateUtil(2 * node + 1, start, mid, i, val);
        else
            updateUtil(2 * node + 2, mid + 1, end, i, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

public:
    int query(int l, int r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }
    void update(int i, int val)
    {
        updateUtil(0, 0, n - 1, i, val);
    }
    void printTree()
    {
        for (auto u : tree)
            cout << u << " ";
        cout << endl;
    }
};

int main()
{
    vector<int> v = {2, 3, 5, 4, 9, 17, 24, 3};
    SegmentTree *st = new SegmentTree(v);
    cout << st->query(3, 5) << endl;
    st->printTree();
    st->update(3, 14);
    st->printTree();
    cout << st->query(3, 5) << endl;
}
