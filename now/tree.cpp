#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<int, TreeNode *> par;
        unordered_map<int, int> vis;

        queue<TreeNode *> q;
        q.push(root);
        TreeNode *beg = NULL;
        while (!q.empty())
        {
            TreeNode *now = q.front();
            q.pop();
            vis[now->val] = 0;
            if (now->left)
            {
                par[now->left->val] = now;
                q.push(now->left);
            }
            if (now->right)
            {
                par[now->right->val] = now;
                q.push(now->right);
            }
            if (now->val == start)
                beg = now;
        }

        q.push(beg);
        int t = 0;
        while (!q.empty())
        {
            for (int i = 0, n = q.size(); i < n; i++)
            {
                t++;
                TreeNode *now = q.front();
                q.pop();
                if (vis[now->val])
                    continue;
                vis[now->val] = 1;
                if (now->left)
                    q.push(now->left);
                if (now->right)
                    q.push(now->right);
                if (par[now->val])
                    q.push(par[now->val]);
            }
        }
        return t;
    }
};

int main()
{

    return 0;
}