#include <bits/stdc++.h>
using namespace std;
long long rec(vector<vector<int>> &dp, vector<int> &time, vector<int> &value, int i, int j)
{
    if (j < 0 || i <= 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (i - time[j] >= 0)
    {
        return dp[i][j] = max(rec(dp, time, value, i, j - 1), rec(dp, time, value, i - time[j], j - 1) + value[j]);
    }
    else
    {
        return dp[i][j] = rec(dp, time, value, i, j - 1);
    }
}

int main()
{
    // 1. 核心改进：必须先读入 T 和 M，才能确定 dp 数组的大小
    int T, M;
    if (!(cin >> T >> M))
        return 0;

    // 2. 核心改进：初始化 dp 数组为 -1，并且大小设为 (T+1) x M
    // 这里的顺序很重要，不能在 cin 之前定义
    vector<vector<int>> dp(T + 1, vector<int>(M, -1));
    vector<int> value(M);
    vector<int> time(M);

    // 3. 核心改进：完善输入循环
    for (int i = 0; i < M; i++)
    {
        cin >> time[i] >> value[i];
    }

    // 4. 核心改进：调用递归函数并输出结果
    // 从最后一棵药（M-1）开始向前决策
    cout << rec(dp, time, value, T, M - 1) << endl;

    return 0;
}
