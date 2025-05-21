#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{

public:
	class node
	{
	public:
		int key;
		int value;
		node *prev;
		node *next;

		node(int _key, int _value)
		{
			key = _key;
			value = _value;
		}
	};

	node *head = new node(-1, -1);
	node *tail = new node(-1, -1);
	int cap;
	map<int, node *> m;

	LRUCache(int capacity)
	{
		cap = capacity;
		head->next = tail;
		tail->prev = head;
	}

	void addnode(node *temp)
	{
		node *dummy = head->next;
		head->next = temp;
		temp->prev = head;
		temp->next = dummy;
		dummy->prev = temp;
	}

	void deletenode(node *temp)
	{
		node *delnext = temp->next;
		node *delprev = temp->prev;
		delnext->prev = delprev;
		delprev->next = delnext;
	}

	int get(int key)
	{
		if (m.find(key) != m.end())
		{
			node *res = m[key];
			m.erase(key);
			int ans = res->value;
			deletenode(res);
			addnode(res);
			m[key] = head->next;
			cout << "Got the value : " << ans
				 << " for the key: " << key << "\n";
			return ans;
		}
		cout << "Did not get any value for the key: "
			 << key << "\n";
		return -1;
	}

	void set(int key, int value)
	{

		cout << "Going to set the (key, value) : ("
			 << key << ", " << value << ")"
			 << "\n";
		if (m.find(key) != m.end())
		{
			node *exist = m[key];
			m.erase(key);
			deletenode(exist);
		}

		if (m.size() == cap)
		{
			m.erase(tail->prev->key);
			deletenode(tail->prev);
		}
		addnode(new node(key, value));
		m[key] = head->next;
	}
};

#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

void infixToPostfix(string s)
{

	stack<char> st;

	string result;

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;

		else if (c == '(')
			st.push('(');

		else if (c == ')')
		{
			while (st.top() != '(')
			{
				result += st.top();
				st.pop();
			}
			st.pop();
		}

		else
		{
			while (!st.empty() && prec(s[i]) <= prec(st.top()))
			{
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.empty())
	{
		result += st.top();
		st.pop();
	}

	cout << result << endl;
}

void dfs(int &timer, vector<vector<int>> &adj, int i, int p, vector<bool> &vis, vector<int> &tin, vector<int> &lin, vector<pair<int, int>> &bridges)
{
	vis[i] = true;
	tin[i] = lin[i] = timer++;
	for (auto u : adj[i])
	{
		if (u == p)
			continue;
		if (vis[u])
		{
			lin[i] = min(lin[i], tin[u]);
		}
		else
		{
			dfs(timer, adj, u, i, vis, tin, lin, bridges);
			lin[i] = min(lin[i], lin[u]);
			if (lin[u] < lin[i])
				bridges.push_back({u, i});
		}
	}
}

vector<pair<int, int>> findBridgesInGraph(vector<vector<int>> &adj)
{
	int timer = 0, n = adj.size();
	vector<pair<int, int>> bridges;
	vector<int> tin(n, -1), lin(n, -1);
	vector<bool> vis(n, false);
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
			dfs(timer, adj, i, -1, vis, tin, lin, bridges);
	}
	return bridges;
}

class Solution
{

	void dfs(int &timer, vector<vector<int>> &adj, int i, int p, vector<int> &tin,
			 vector<int> &lin, vector<bool> &vis, vector<vector<int>> &res)
	{
		vis[i] = true;
		tin[i] = lin[i] = timer++;
		for (auto u : adj[i])
		{
			if (u == p)
				continue;
			if (vis[u])
				lin[i] = min(lin[i], tin[u]);
			else
			{
				dfs(timer, adj, u, i, tin, lin, vis, res);
				lin[i] = min(lin[i], lin[u]);
				if (lin[i] < lin[u])
					res.push_back({i, u});
			}
		}
	}

public:
	vector<vector<int>> findCriticalConnections(int n, vector<vector<int>> &connections)
	{
		int timer = 0;
		vector<int> tin(n, -1), lin(n, -1);
		vector<bool> vis(n, false);
		vector<vector<int>> res;
		for (int i = 0; i < n; i++)
		{
			if (!vis[i])
				dfs(timer, connections, i, -1, tin, lin, vis, res);
		}
		return res;
	}
};

int main()
{
	cout << "Going to test the LRU "
		 << "Cache Implementation\n";

	LRUCache *cache = new LRUCache(2);

	cache->set(1, 10);

	cache->set(2, 20);
	cout << "Value for the key: 1 is "
		 << cache->get(1) << "\n";

	cache->set(3, 30);

	cout << "Value for the key: 2 is "
		 << cache->get(2) << "\n";

	cache->set(4, 40);
	cout << "Value for the key: 1 is "
		 << cache->get(1) << "\n";
	cout << "Value for the key: 3 is "
		 << cache->get(3) << "\n";
	cout << "Value for the key: 4 is "
		 << cache->get(4) << "\n";

	return 0;
}
