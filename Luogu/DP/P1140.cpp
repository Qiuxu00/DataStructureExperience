#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> letter = {{'A', 0},
                                   {'C', 1},
                                   {'G', 2},
                                   {'T', 3},
                                   {'-', 4}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> vec = {{5, -1, -2, -1, -3},
                               {-1, 5, -2, -3, -4},
                               {-2, -3, 5, -2, -2},
                               {-1, -2, -2, 5, -1},
                               {-3, -4, -2, -1, 0}};
    int n, m;
    string str_1;
    string str_2;
    cin >> n >> str_1 >> m >> str_2;
    // int n = 4;
    // string str_1 = "AAAA";
    // int m = 3;
    // string str_2 = "AAA";
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i < dp[0].size(); i++)
    {
        dp[0][i] = dp[0][i - 1] + vec[letter[str_1[i - 1]]][letter['-']];
    }
    for (int i = 1; i < dp.size(); i++)
    {
        dp[i][0] = dp[i - 1][0] + vec[letter[str_2[i - 1]]][letter['-']];
    }
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            dp[i][j] = max({dp[i - 1][j] + vec[letter[str_2[i - 1]]][letter['-']],
                            dp[i][j - 1] + vec[letter[str_1[j - 1]]][letter['-']],
                            dp[i - 1][j - 1] + vec[letter[str_1[j - 1]]][letter[str_2[i - 1]]]});
        }
    }
    cout << dp[m][n] << endl;
}