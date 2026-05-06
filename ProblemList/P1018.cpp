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
    vector<bool> ok(C + 1);
    vector<bool> temp_ok(ok.size());
    temp_ok[0] = true;
    vector<int> temp_dp(dp.size());

    ok[0] = true;
    for (int i = 0; i < N; i++)
    {

        for (int j = 1; j <= C; j++)
        {
            if (ok[j])
            {
                if (j - size[i] >= 0 && ok[j - size[i]])
                {
                    temp_ok[j] = true;
                    temp_dp[j] = max(dp[j], dp[j - size[i]] + val[i]);
                }
                temp_ok[j] = ok[j];
            }
            else
            {
                if (j - size[i] >= 0 && ok[j - size[i]])
                {
                    temp_ok[j] = true;
                    temp_dp[j] = dp[j - size[i]] + val[i];
                }
                else
                {
                    temp_dp[j] = 0;
                    temp_ok[j] = false;
                }
            }
        }
        for (int i = 0; i < ok.size(); i++)
        {
            ok[i] = temp_ok[i];
            dp[i] = temp_dp[i];
        }
    }
    res.push_back(dp[C]);
}

// void test()
// {
//     vector<int> res;
//     solve(res);
// }

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