#include <bits/stdc++.h>
using namespace std;
int main()
{
    string X = "chocolate";
    string Y = "chips";
    string Z = "cchocohilaptes";
    vector<vector<bool>> dp(X.size() + 1, vector<bool>(Y.size() + 1));
    dp[0][0] = 1;

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            else if (i == 0)
            {
                if (Z[i + j - 1] == Y[j - 1] && dp[0][j - 1])
                {
                    dp[0][j] = 1;
                }
            }
            else if (j == 0)
            {
                if (Z[i + j - 1] == X[i - 1] && dp[i - 1][0])
                {
                    dp[i][0] = 1;
                }
            }
            else
            {
                if (dp[i - 1][j] && Z[i + j - 1] == X[i - 1])
                {
                    dp[i][j] = 1;
                }
                else if (Z[i + j - 1] == Y[j - 1] && dp[i][j - 1])
                {
                    dp[i][j] = 1;
                }
            }
        }
    }
    cout << boolalpha << dp[X.size()][Y.size()] << endl;
    return 0;
}