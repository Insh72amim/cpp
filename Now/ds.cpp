int angle(stack<vector<int>> &s)
{
    if (s.size() < 3)
        return false;
    vector<int> v1, v2, v3;
    v1 = s.top();
    s.pop();
    v2 = s.top();
    s.pop();
    v3 = s.top();
    s.pop();
    double m12, m23;
    m12 = v2[0] == v1[0] ? INT_MAX : (v2[1] - v1[1]) / (v2[0] - v1[0]);
    m23 = v2[0] == v3[0] ? INT_MAX : (v2[1] - v3[1]) / (v2[0] - v3[0]);
    s.push(v3), s.push(v2), s.push(v1);
    return m12 > m23;
}