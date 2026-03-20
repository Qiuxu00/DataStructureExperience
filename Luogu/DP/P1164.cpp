#include <bits/stdc++.h>
using namespace std;

long long rec(vector<vector<long long>> &dp, vector<int> &cost, vector<vector<bool>> &ready, int i, int j)
{
    if (ready[i][j])
    {
        return dp[i][j];
    }
    int result = 0;
    int left_ = 0;
    int up_ = 0;
    if (cost[j] >= i)
    {

        if (j - 1 >= 0)
        {
            left_ = rec(dp, cost, ready, i, j - 1);
        }
        if (cost[j] == i)
        {
            left_++;
        }
    }

    if (cost[j] < i)
    {
        if (j - 1 >= 0)
        {
            up_ = rec(dp, cost, ready, i - cost[j], j - 1) + rec(dp, cost, ready, i, j - 1);
        }
    }
    result += (left_ + up_);
    dp[i][j] = result;
    ready[i][j] = 1;
    return result;
}

int main()
{
    // 1. 补全输入步骤
    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    // 2. 动态初始化 DP 表（根据输入的 m 和 n）
    // 行：0 到 m 元 (m + 1)
    // 列：0 到 n-1 个物品 (n)
    vector<vector<long long>> dp(m + 1, vector<long long>(n, 0));
    vector<vector<bool>> ready(m + 1, vector<bool>(n, false));

    // 3. 执行搜索并输出结果
    // 从最后一道菜 (n-1) 开始，带着总预算 m 递归
    cout << rec(dp, cost, ready, m, n - 1) << endl;

    return 0;
    return 0;
}