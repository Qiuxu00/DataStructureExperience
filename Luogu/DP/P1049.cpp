#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, n;
    if (!(cin >> V >> n))
        return 0; // 读入总体积 V 和物品数量 n
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i]; // 循环读入每个物品的体积
    }
    vector<vector<int>> dp(V + 1, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0) // 特殊处理
            {
                dp[i][j] = (i >= v[j]) ? (i - v[j]) : i;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
                if (i >= v[j])
                {
                    dp[i][j] = min(dp[i][j], dp[i - v[j]][j - 1]);
                }
            }
        }
    }
    cout << dp[V][n - 1] << endl;
    return 0;
}
