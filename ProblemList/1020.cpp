#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long> &res)
{
    int N;
    cin >> N;
    vector<int> L(N);
    vector<int> R(N);
    for (int i = 0; i < N; i++)
    {
        cin >> L[i] >> R[i];
    }
    vector<vector<long long>> dp(N, vector<long long>(N));
    for (int step = 1; step < N; step++)
    {
        for (int start = 0; start < N - step; start++)
        {
            dp[start][start + step] = dp[start + 1][start + step] + L[start] * R[start] * R[start + step];
            for (int k = start + 1; k < (start + step); k++)
            {
                dp[start][start + step] = min(dp[start][start + step], dp[start][k] + dp[k + 1][start + step] + (long long)L[start] * (long long)R[k] * (long long)R[start + step]);
            }
        }
    }
    res.push_back(dp[0][N - 1]);
}

int main()
{
    int n;
    cin >> n;
    vector<long long> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (long long i : res)
    {
        cout << i << endl;
    }
    return 0;
}