#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string solve(stack<string> &s)
    {
        if (s.size() == 0)
            return "";
        int sum = 0;
        while (s.size() > 0)
        {
            if (s.top() == "+")
            {
                s.pop();
                sum += stoi(s.top());
                s.pop();
            }
            else if (s.top() == "-")
            {
                s.pop();
                sum -= stoi(s.top());
                s.pop();
            }
            else
            {
                sum += stoi(s.top());
                s.pop();
            }
        }
        return to_string(sum);
    }

public:
    int calculate(string str)
    {
        stack<string> s;
        string now = "";
        for (int i = 0, n = str.size(); i < n; i++)
        {
            char u = str[i];
            if (u - '0' >= 0 && u - '0' <= 9)
                now.push_back(u);

            if ((u == ' ' || u == ')' || u == '(' || u == '+' || u == '-' || i == n - 1) && now.size() > 0)
                s.push(now), now.clear();

            if (u == ')' || u == '(' || u == '+' || u == '-')
                now.clear(), now.push_back(u), s.push(now), now.clear();

            if (s.size() > 0 && s.top() == ")")
            {
                stack<string> temp;
                s.pop();
                while (s.size() > 0 && s.top() != "(")
                    temp.push(s.top()), s.pop();
                s.pop();
                string val = solve(temp);
                s.push(val);
            }
        }

        stack<string> st;
        while (s.size() > 0)
            st.push(s.top()), s.pop();
        string ans = solve(st);
        return stoi(ans);
    }
};

int main()
{
    Solution x;
    string s = "1+1";
    vector<string> v = {" (231+(456   +55   + 234)-3)+(64   +   85)"};

    for (auto u : v)
        cout << x.calculate(u) << endl;

    return 0;
}