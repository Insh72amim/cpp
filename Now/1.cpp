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
      if (curr->val != INT_MAX)
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
    int i = q.front().second;
    q.pop();

    if (!curr || i >= n)
      continue;

    TreeNode *left = nullptr, *right = nullptr;
    if (2 * i + 1 < n)
      left = new TreeNode(v[2 * i + 1]);
    if (2 * i + 2 < n)
      right = new TreeNode(v[2 * i + 2]);
    curr->left = left;
    curr->right = right;

    q.push({left, 2 * i + 1});
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
        req.push_back(INT_MAX);
      else
        req.push_back(stoi(temp));
      temp.clear();
    }
    else
      temp.push_back(u);
  }
  return req;
}
void pri(TreeNode *root)
{
  if (!root)
    return;
  cout << root->val << " ";
  if (root->left)
    cout << root->left->val << " ";
  if (root->right)
    cout << root->right->val << " ";
  cout << endl;
  pri(root->left);
  pri(root->right);
}
class Codec
{
public:
  string serialize(TreeNode *root)
  {
    if (!root)
      return "";
    string s = "";
    s += serialize(root->left);
    s += to_string(root->val);
    s += "#";
    s += serialize(root->right);
    return s;
  }

  vector<int> myVector(string data)
  {
    vector<int> req;
    string temp = "";
    for (auto u : data)
    {
      if (u == '#')
      {
        req.push_back(stoi(temp));
        temp.clear();
      }
      else
        temp.push_back(u);
    }
    return req;
  }
  TreeNode *makeBst(vector<int> v, int i, int j)
  {
    TreeNode *root = nullptr;
    if (i > j)
      return root;
    int k = (i + j) / 2;
  }
  TreeNode *deserialize(string data)
  {
    vector<int> v = myVector(data);
    return makeBst(v, 0, v.size() - 1);
  }
};

class Solution
{
public:
  vector<pair<TreeNode *, TreeNode *>> mm;

  void mahvo(TreeNode *root, TreeNode *prev)
  {
    if (!root)
      return;
    mahvo(root->left, prev);
    if (prev && prev->val > root->val)
      mm.push_back({prev, root});
    prev = root;
    mahvo(root->right, prev);
  }

  void recoverTree(TreeNode *root)
  {
    TreeNode *prev = NULL;
    mahvo(root, prev);
    if (mm.size() > 1)
      swap(mm[0].first->val, mm[1].second->val);
    else
      swap(mm[0].first->val, mm[0].second->val);
  }
};

int main()
{

  return 0;
}
