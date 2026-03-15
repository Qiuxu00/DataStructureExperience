#include <bits/stdc++.h>
using namespace std;

long long k_s_min(vector<int> &vec, vector<long long> &dp, vector<bool> &dped, int k)
{
    if (k == 0)
    {
        return 0;
    }
    if (dped[k])
    {
        return dp[k];
    }
    long long Min;
    if (k - 1 >= 0)
    {
        Min = k_s_min(vec, dp, dped, k - 1) + abs(vec[k] - vec[k - 1]);
    }
    long long min_ = 2e8;
    if (k - 2 >= 0)
    {
        min_ = k_s_min(vec, dp, dped, k - 2) + abs(vec[k] - vec[k - 2]);
    }
    dp[k] = min(Min, min_);
    dped[k] = true;
    return dp[k];
}

int main()
{
    // 优化输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    if (!(cin >> n))
        return 0;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    // 初始化 DP 相关的数组
    vector<bool> dped(n, false);
    vector<long long> dp(n, 0);

    // 计算到达最后一块石头（下标 n-1）的最小代价
    cout << k_s_min(vec, dp, dped, n - 1) << endl;

    return 0;
}