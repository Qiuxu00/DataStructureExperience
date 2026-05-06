#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long> &res)
{
    int n, k;
    cin >> n >> k;

    vector<long long> nums(n);
    for (auto &i : nums)
    {
        cin >> i;
    }
    vector<vector<long long>> dp(k + 1, vector<long long>(n));
    dp[0][0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = dp[0][i - 1] + nums[i];
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int p = i - 1; p < j; p++)
            {
                dp[i][j] = max(dp[i][j], (dp[i - 1][p]) * (dp[0][j] - dp[0][p]));
            }
        }
    }
    res.push_back(dp[k][n - 1]);
}

int main()
{
    int n;
    cin >> n;
    vector<long long> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (auto i : res)
    {
        cout << i << endl;
    }

    return 0;
}