#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rat(m, vector<int>(3));
    for (auto &v : rat)
    {
        for (int &i : v)
        {
            cin >> i;
        }
    }
    vector<int> dp(m + 1);
    dp[1] = 1;
    for (int k = 2; k < dp.size(); k++)
    {
        dp[k] = 1;
        for (int j = 1; j < k; j++)
        {
            if (abs(rat[j - 1][1] - rat[k - 1][1]) + abs(rat[j - 1][2] - rat[k - 1][2]) <= (rat[k - 1][0] - rat[j - 1][0]))
            {
                dp[k] = max(dp[k], dp[j] + 1);
            }
        }
    }
    int max_ = 0;
    for (auto i : dp)
    {
        max_ = max(max_, i);
    }
    cout << max_ << endl;
    return 0;
}