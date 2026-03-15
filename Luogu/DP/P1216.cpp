#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 开启 Fast I/O，优化输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r;
    if (!(cin >> r))
        return 0;

    // 初始化二维 vector，外层大小为 r
    vector<vector<int>> triangle(r);

    for (int i = 0; i < r; ++i)
    {
        // 第 i 行（从0开始）会有 i + 1 个数字
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; ++j)
        {
            cin >> triangle[i][j];
        }
    }

    // --- 此时 triangle 已经存储了所有的数字三角形数据 ---
    // 你可以在这里开始编写你的 DP 逻辑

    vector<vector<long long>> dp(r);
    for (int i = 0; i < r; ++i)
    {
        // 第 i 行（从0开始）会有 i + 1 个数字
        dp[i].resize(i + 1);
        for (int j = 0; j <= i; ++j)
        {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j - 1 >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]); // remenber add currently weight
            }
            if (j < i)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + triangle[i][j]);
            }
        }
    }
    long long max_ = 0;
    for (int i = 0; i < r; i++)
    {
        max_ = max(dp[r - 1][i], max_);
    }
    cout << max_ << endl;
    return 0;
}