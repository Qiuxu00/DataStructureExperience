#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> mat = {{20, 35}, {35, 10}, {10, 15}, {15, 20}};
    vector<vector<int>> dp(mat.size(), vector<int>(mat.size()));
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = i; j < mat.size(); j++)
        {
            dp[j][i] = 0;
        }
    }

    for (int i = 1; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size() - i; j++)
        {
            dp[j][j + i] = dp[j][j] + dp[j + 1][j + i] + mat[j].first * mat[j].second * mat[j + i].second; // 加上这一行的目的就是初始化值，以免爆炸
            for (int k = j + 1; k < j + i; k++)
            {
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + mat[j].first * mat[k].second * mat[j + i].second);
            }
        }
    }
    cout << dp[0][mat.size() - 1] << endl;
    return 0;
}