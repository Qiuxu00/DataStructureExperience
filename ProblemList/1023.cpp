#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &res)
{
    int n, E, s, t, M;
    cin >> n >> E >> s >> t >> M;
    vector<int> B(n);
    for (int &i : B)
    {
        cin >> i;
    }
    vector<vector<pair<int, int>>> Edge(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < E; i++)
    {
        int from, to, len;
        cin >> from >> to >> len;
        Edge[from].push_back({to, len});
        Edge[to].push_back({from, len});
    }
    // dp[i][j]表示的是在最多能够使用i块钱的情况下，从起点到j国的最短距离
    vector<vector<int>> dp(M + 1, vector<int>(n + 1, 1e9));
    for (int i = 0; i <= M; i++)
    {
        dp[i][s] = 0;
    }

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j != s)
            {
                if (i < B[j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    for (auto p : Edge[j])
                    {
                        if (dp[i - B[j - 1]][p.first] == 1e9)
                        {
                            dp[i][j] = min(dp[i][j], (int)1e9);
                        }
                        else
                        {
                            dp[i][j] = min(dp[i][j], dp[i - B[j - 1]][p.first] + p.second);
                        }
                    }
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                }
            }
        }
    }
    if (dp[M][t] != 1e9)
    {
        res.push_back(dp[M][t]);
    }
    else
    {
        res.push_back(-1);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (int i : res)
    {
        cout << i << endl;
    }
    return 0;
}