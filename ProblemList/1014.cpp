#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &res)
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &i : nums)
    {
        cin >> i;
    }
    vector<int> dp(n);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
    }
    int max_ = dp[0];
    for (int i = 1; i < dp.size(); i++)
    {
        if (dp[i] > max_)
        {
            max_ = dp[i];
        }
    }
    res.push_back(max_);
}

int main()
{
    int n;
    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (int i : res)
    {
        cout << i << endl;
    }
    return 0;
}