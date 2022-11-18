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

class Solution
{
public:
    vector<TreeNode *> v;
    void makevec(TreeNode *root)
    {
        if (!root)
            return;
        makevec(root->left);
        v.push_back(root);
        makevec(root->right);
    }
    TreeNode *makeBst(int i, int j)
    {
        if (i > j)
            return NULL;
        int k = (i + j) / 2;
        v[k]->left = makeBst(i, k - 1);
        v[k]->right = makeBst(k + 1, j);
        return v[k];
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        makevec(root);
        return makeBst(0, v.size() - 1);
    }
};

int main()
{
    cout << "Helllo World";
}