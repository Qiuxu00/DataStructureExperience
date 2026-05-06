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
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] >= nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int max_ = 0;
    for (int i : dp)
    {
        max_ = max(max_, i);
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