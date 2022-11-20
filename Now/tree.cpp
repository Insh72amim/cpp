#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void printvector(vector<int> v)
{
    for (auto u : v)
        cout << u << " ";
    cout << "\n";
}
void printTreebfs(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->val != -1)
                cout << curr->val << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << "\n";
    }
}
TreeNode *v2t(vector<int> v)
{
    if (v.size() == 0)
        return NULL;
    int n = v.size();

    queue<pair<TreeNode *, int>> q;
    TreeNode *root = new TreeNode(v[0]);
    q.push({root, 0});

    while (!q.empty())
    {
        TreeNode *curr = q.front().first;
        TreeNode *left = nullptr, *right = nullptr;
        int i = q.front().second;
        q.pop();

        if (2 * i + 1 < n)
            left = new TreeNode(v[2 * i + 1]);
        if (2 * i + 2 < n)
            right = new TreeNode(v[2 * i + 2]);

        curr->left = left;
        curr->right = right;

        if (left)
            q.push({left, 2 * i + 1});
        if (2 * i + 2 < n)
            q.push({right, 2 * i + 2});
    }

    return root;
}
vector<int> s2v(string s)
{
    vector<int> req;
    string temp = "";
    for (auto u : s)
    {
        if (u == ' ' || u == '[')
            continue;
        else if (u == ',' || u == ']')
        {
            if (temp == "null")
                req.push_back(-1);
            else
                req.push_back(stoi(temp));
            temp.clear();
        }
        else
            temp.push_back(u);
    }
    return req;
}

int main()
{

    string s = " [ 4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]";
    vector<int> v = s2v(s);
    // printvector(v);
    TreeNode *root = v2t(v);
    // printTreebfs(root);
    return 0;
}
