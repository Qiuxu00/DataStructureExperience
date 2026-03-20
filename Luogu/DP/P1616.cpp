#include <bits/stdc++.h>
using namespace std;

long long rec(vector<vector<long long>> &dp, vector<int> &t_cost, vector<int> &value, int i, int j)
{
    if (i <= 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (i - t_cost[j] >= 0)
    {
        return dp[i][j] = max(rec(dp, t_cost, value, i, j - 1), rec(dp, t_cost, value, i - t_cost[j], j) + value[j]);
    }
    else
    {
        return dp[i][j] = dp[i][j - 1];
    }
}

int main()
{
    int t = 70, m = 3;
    vector<vector<long long>> dp(t + 1, vector<long long>(m, -1));
    vector<int> t_cost = {71, 69, 1};
    vector<int> value = {100, 1, 2};
    cout << rec(dp, t_cost, value, 70, 2) << endl;
    return 0;
}