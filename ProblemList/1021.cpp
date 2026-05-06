#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &res)
{
    int L, K;
    cin >> L >> K;
    vector<int> size(K);
    vector<int> val(K);
    for (int i = 0; i < K; i++)
    {
        cin >> size[i] >> val[i];
    }
    vector<int> dp(L + 1);
    for (int i = 0; i < K; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            if (j - size[i] >= 0)
            {
                dp[j] = max(dp[j], dp[j - size[i]] + val[i]);
            }
        }
    }
    res.push_back(dp[L]);
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