#include <bits/stdc++.h>
using namespace std;
int main()
{
    int time_limit, n;
    if (!(cin >> time_limit >> n))
        return 0;

    // 2. 准备数据：按照你的逻辑使用 vector 存储
    vector<int> cost(n);
    vector<int> score(n);
    for (int i = 0; i < n; i++)
    {
        // 注意：P2722 的输入格式是先给分数，再给时间
        cin >> score[i] >> cost[i];
    }
    vector<int> dp(time_limit + 1);
    for (int j = 0; j < cost.size(); j++)
    {
        for (int i = 1; i < dp.size(); i++)
        {
            if (i - cost[j] >= 0)
            {
                dp[i] = max(dp[i], dp[i - cost[j]] + score[j]);
            }
        }
    }
    cout << dp[time_limit] << endl;
    return 0;
}