#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> coin = {1, 2, 3, 4, 5};
    vector<int> dp(coin.size() + 1);
    dp[0] = 0;
    dp[1] = coin[0];
    vector<pair<int, bool>> pre(dp.size());
    pre[1] = {0, 1};
    pre[0] = {0, 0};
    for (int i = 2; i < dp.size(); i++)
    {
        dp[i] = dp[i - 1]; // Don't select
        if (pre[i - 1].second)
        {
            pre[i] = {i - 1, 0};
        }
        else
        {
            pre[i] = {pre[i - 1].first, 0};
        }
        if (dp[i - 2] + coin[i - 1] > dp[i])
        {
            dp[i] = dp[i - 2] + coin[i - 1];
            if (pre[i - 2].second)
            {
                pre[i] = {i - 2, 1};
            }
            else
            {
                pre[i] = {pre[i - 2].first, 1};
            }
        }
    }
    cout << dp[dp.size() - 1] << endl;
    cout << "The selection of coins are" << endl;
    int cur = dp.size() - 1;
    vector<int> result;
    while (cur != 0)
    {
        if (pre[cur].second)
        {
            result.push_back(coin[cur - 1]);
            cur = pre[cur].first;
        }
        else
        {
            cur = pre[cur].first;
        }
    }
    for (int i : result)
    {
        cout << " " << i << " ";
    }
    cout << endl;
    return 0;
}