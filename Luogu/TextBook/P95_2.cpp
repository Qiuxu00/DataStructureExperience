#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> p_1 = {1, 0, 0, 1, 0, 1, 0, 1};
    vector<int> p_2 = {0, 1, 0, 1, 0, 1, 1, 0};
    vector<vector<int>> dp(p_1.size() + 1, vector<int>(p_2.size() + 1));
    vector<int> pre(p_1.size());
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if (p_1[i - 1] == p_2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                pre[i - 1] = i - 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[dp.size() - 1][dp[0].size() - 1] << endl;
    vector<int> str;
    int i = p_1.size(), j = p_2.size();
    while (i > 0 && j > 0)
    {
        if (p_1[i - 1] == p_2[j - 1])
        {
            str.push_back(p_1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(str.begin(), str.end());

    // 打印序列
    for (int x : str)
        cout << x << " ";
    cout << endl;

    return 0;
}