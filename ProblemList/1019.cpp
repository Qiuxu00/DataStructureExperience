#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &res)
{
    int N, C;
    cin >> N >> C;
    vector<int> size(N);
    vector<int> val(N);
    for (int i = 0; i < N; i++)
    {
        cin >> size[i] >> val[i];
    }
    vector<int> dp(C + 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = C; j > 0; j--)
        {
            if (j - size[i] >= 0)
            {
                dp[j] = max(dp[j], dp[j - size[i]] + val[i]);
            }
        }
    }
    res.push_back(dp[C]);
}

int main()
{
    vector<int> res;
    int n;
    cin >> n;

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