#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &res)
{
    string str_1;
    string str_2;
    cin >> str_1 >> str_2;
    vector<vector<int>> dp(str_1.size() + 1, vector<int>(1 + str_2.size()));
    for (int i = 1; i <= str_1.size(); i++)
    {
        for (int j = 1; j <= str_2.size(); j++)
        {
            if (str_1[i - 1] == str_2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    res.push_back(dp[str_1.size()][str_2.size()]);
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