#include <bits/stdc++.h>
using namespace std;

class Trie
{
    vector<Trie *> child;
    bool isEnd;

public:
    Trie()
    {
        child.resize(26);
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
    void insert(string s)
    {
        Trie *node = this;
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i] << " ";
            int p = s[i] - 'a';
            if (node->child[p] == NULL)
                node->child[p] = new Trie();
            node = node->child[p];
        }
        node->isEnd = true;
    }
    bool search(string s)
    {
        Trie *node = this;
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i] << " ";
            int p = s[i] - 'a';
            if (node->child[p] == NULL)
                return false;
            node = node->child[p];
        }
        return node->isEnd;
    }

    bool startsWith(string s)
    {
        Trie *node = this;
        for (int i = 0; i < s.size(); i++)
        {
            int p = s[i] - 'a';
            cout << s[i] << " ";
            if (node->child[p] == NULL)
                return false;
            node = node->child[p];
        }
        return true;
    }
};

int main()
{
    Trie *trie = new Trie();
    trie->insert("syed");
    cout << trie->search("syed") << endl;
}
