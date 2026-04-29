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
    for (int i = 0; i < n; i++)
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