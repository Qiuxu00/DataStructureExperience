#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &res)
{
    int n;
    cin >> n;
    vector<int> r(2);
    vector<int> nums(n);
    for (auto &i : nums)
    {
        cin >> i;
    }
    vector<int> dp(n);
    dp[0] = 1;
    for (int cur = 1; cur < n; cur++)
    {
        dp[cur] = 1;
        for (int i = 0; i < cur; i++)
        {
            if (nums[cur] <= nums[i] && dp[i] + 1 > dp[cur])
            {
                dp[cur] = dp[i] + 1;
            }
        }
    }
    int max_ = 0;
    for (int i : dp)
    {
        if (i > max_)
        {
            max_ = i;
        }
    }
    r[0] = max_;
    dp[0] = 1;
    for (int cur = 1; cur < n; cur++)
    {
        dp[cur] = 1;
        for (int i = 0; i < cur; i++)
        {
            if (nums[cur] > nums[i] && dp[i] + 1 > dp[cur])
            {
                dp[cur] = dp[i] + 1;
            }
        }
    }
    max_ = 0;
    for (int i : dp)
    {
        if (i > max_)
        {
            max_ = i;
        }
    }
    r[1] = max_;
    res.push_back(r);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (auto v : res)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}