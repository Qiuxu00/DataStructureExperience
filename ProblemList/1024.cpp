#include <bits/stdc++.h>
using namespace std;

void solve(vector<double> &res)
{
    int n;
    cin >> n;
    vector<double> prp(2 * n + 1);
    vector<int> nums(n);
    for (int &i : nums)
    {
        cin >> i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> prp[2 * i + 1];
    }
    for (int i = 0; i < n + 1; i++)
    {
        cin >> prp[2 * i];
    }
    // dp[i][j]表示的是包括ij在内的从i到j的所有关键字构成的一个最优二叉树的搜索期望
    vector<vector<double>> dp(n, vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = prp[2 * i + 1] + prp[2 * i] + prp[2 * i + 2];
    }
    vector<double> prep(2 * n + 2);
    prep[0] = 0;
    for (int i = 1; i < 2 * n + 2; i++)
    {
        prep[i] = prep[i - 1] + prp[i - 1];
    }
    for (int step = 1; step < n; step++)
    {
        for (int start = 0; start < n - step; start++)
        {
            dp[start][start + step] = 1e9;
            for (int k = start; k <= start + step; k++)
            {
                double left_dp = (k == start) ? 0.0 : dp[start][k - 1];
                double right_dp = (k == start + step) ? 0.0 : dp[k + 1][start + step];

                double w = prep[2 * (start + step) + 3] - prep[2 * start];

                dp[start][start + step] = min(dp[start][start + step], left_dp + right_dp + w);
            }
        }
    }
    res.push_back(dp[0][n - 1]);
}

int main()
{
    int n;
    cin >> n;
    vector<double> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (auto i : res)
    {
        printf("%.6f\n", i);
    }
    return 0;
}