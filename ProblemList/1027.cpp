#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &res)
{
    int N;
    cin >> N;
    vector<tuple<int, int, int>> act;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        act.emplace_back(b, a, c);
    }
    sort(act.begin(), act.end());
    vector<int> dp(N);
    vector<vector<int>> actv(0, vector<int>(3));
    for (int i = 0; i < N; i++)
    {
        auto [a0, a1, a2] = act[i];
        actv.push_back({a1, a0, a2});
    }
    dp[0] = actv[0][2];
    for (int i = 1; i < N; i++)
    {
        int notchoose = dp[i - 1];
        int choose = actv[i][2];
        for (int j = 0; j < i; j++)
        {
            if (actv[i][0] >= actv[j][1])
            {
                choose = max(choose, dp[j] + actv[i][2]);
            }
        }
        dp[i] = max(choose, notchoose);
    }
    res.push_back(dp[N - 1]);
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