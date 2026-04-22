#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> w(n);
    for (auto &i : w)
    {
        cin >> i;
    }

    vector<vector<int>> dp(w.size(), vector<int>(w.size()));
    vector<int> wp(w.size() + 1);
    wp[0] = 0;
    wp[1] = w[0];
    for (int i = 2; i < wp.size(); i++)
    {
        wp[i] = wp[i - 1] + w[i - 1];
    }

    for (int step = 1; step < w.size(); step++)
    {
        for (int start = 0; start < w.size() - step; start++)
        {
            int sum = +(wp[start + step + 1] - wp[start]);
            dp[start][start + step] = dp[start][start] + dp[start + 1][start + step] + sum;
            for (int k = 1; k < step; k++)
            {
                dp[start][start + step] = min(dp[start][start + step], dp[start][start + k] + dp[start + k + 1][start + step] + sum);
            }
        }
    }
    cout << dp[0][w.size() - 1] << endl;
    return 0;
}