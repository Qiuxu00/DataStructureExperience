#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> w = {1, 1, 10, 100};
    vector<vector<int>> dp(w.size() + 1, vector<int>(w.size() + 1));
    for (int i = 1; i <= w.size(); i++)
    {
        dp[i][i] = w[i - 1];
    }
    for (int step = 1; step < w.size(); step++)
    {
        for (int start = 1; start < w.size() - step + 1; start++)
        {
            if (step == 1)
            {
                dp[start][start + step] = w[start - 1] + dp[start + 1][start + step];
            }
            else
            {
                dp[start][start + step] = w[start - 1] + dp[start + 1][start + step] * 2;
                for (int k = start + 1; k < start + step; k++)
                {
                    if (k + 1 == start + step)
                    {
                        dp[start][start + step] = min(dp[start][start + step], dp[start][k] * 2 + w[k]);
                    }
                    else
                    {
                        dp[start][start + step] = min(dp[start][start + step], (dp[start][k] + dp[k + 1][start + step]) * 2);
                    }
                }
            }
        }
    }
    cout << dp[1][w.size()] << endl;

    return 0;
}