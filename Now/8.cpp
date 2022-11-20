#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
	vector<Trie *> vchild;
	bool isend;

	Trie()
	{
		this->isend = false;
		for (int i = 0; i < 26; i++)
			vchild.push_back(NULL);
	}

	void insert(string w)
	{
		int n = w.size();
		Trie *prev = this;
		for (int i = 0; i < n; i++)
		{
			int j = w[i] - 'a';
			if (!prev->vchild[j])
				prev->vchild[j] = new Trie();
			prev = prev->vchild[j];
		}
		if (prev)
			prev->isend = true;
	}

	bool search(string w)
	{
		int n = w.size();
		Trie *prev = this;
		for (int i = 0; i < n; i++)
		{
			int j = w[i] - 'a';
			if (!prev->vchild[j])
				return false;
			prev = prev->vchild[j];
		}
		return prev->isend;
	}

	bool startsWith(string w)
	{
		int n = w.size();
		Trie *prev = this;
		for (int i = 0; i < n; i++)
		{
			int j = w[i] - 'a';
			if (!prev || !prev->vchild[j])
				return false;
			prev = prev->vchild[j];
		}
		return true;
	}
};

class Solution
{
public:
	unordered_map<TreeNode *> fx, gx;
	void maxPathSum(TreeNode *root)
	{
		if (!root)
			return;
	}
	int maxPathSum(TreeNode *root)
	{
	}
};

int main()
{
	return 0;
}