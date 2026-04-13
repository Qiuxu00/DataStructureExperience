// 01背包问题（采药问题）最简洁递推写法
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, M;
    cin >> T >> M;
    vector<int> time(M), value(M), dp(T + 1);
    for (int i = 0; i < M; ++i)
        cin >> time[i] >> value[i];
    for (int i = 0; i < M; ++i)
        for (int j = T; j >= time[i]; --j)
            dp[j] = max(dp[j], dp[j - time[i]] + value[i]);
    cout << dp[T] << '\n';
    return 0;
}
