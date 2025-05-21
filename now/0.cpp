

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        vector<pair<int, int>> vp;
        int z = 0;
        for (auto u : nums)
        {
            int mv = 0, f = 1;
            while (u > 0)
            {
                mv = f * mapping[u % 10] + mv;
                u /= 10;
                f *= 10;
            }
            vp.push_back({mv, z});
            z++;
        }
        sort(vp.begin(), vp.end());
        vector<int> res;
        for (auto u : vp)
        {
            res.push_back(nums[u.second]);
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    int x = 12345678;
    vector<int> mapping = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
    vector<int> nums = {991, 338, 38};
    vector<int> res = s->sortJumbled(mapping, nums);
    for (auto u : res)
        cout << u << ' ';
    cout << endl;
    return 0;
}
