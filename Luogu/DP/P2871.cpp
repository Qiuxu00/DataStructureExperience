#include <bits/stdc++.h>
using namespace std;

long long rec(vector<vector<int>> &dp, vector<int> &value, vector<int> &weight, int i, int j)
{
    if (i <= 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (i - weight[j] >= 0)
    {
        return dp[i][j] = max(rec(dp, value, weight, i, j - 1), rec(dp, value, weight, i - weight[j], j - 1) + value[j]);
    }
    else
    {
        return dp[i][j] = rec(dp, value, weight, i, j - 1);
    }
}
int main()
{
    int N, M;
    if (!(cin >> N >> M))
        return 0; // 1. 先读入规模

    vector<int> weight(N), value(N); // 2. 分配空间
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> value[i]; // 3. 读入数据
    }

    // 4. 初始化 DP 数组，注意列数应该是 N
    vector<vector<int>> dp(M + 1, vector<int>(N, -1));

    // 5. 调用递归，物品索引从 N-1 开始
    cout << rec(dp, value, weight, M, N - 1) << endl;

    return 0;
}