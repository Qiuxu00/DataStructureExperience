#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> mat = {5, 10, 3, 12, 5, 50};
    vector<vector<int>> dp(mat.size() - 1, vector<int>(mat.size() - 1));
    for (int step = 1; step < mat.size(); step++)
    {
        for (int start = 0; start < mat.size() - step - 1; start++)
        {
            dp[start][start + step] = dp[start + 1][start + step] + mat[start] * mat[start + 1] * mat[start + step + 1];
            for (int k = start + 1; k < start + step; k++)
            {
                dp[start][start + step] = min(dp[start][start + step], dp[start][k] + dp[k + 1][start + step] + mat[start] * mat[k + 1] * mat[start + step + 1]);
            }
        }
    }
    cout << dp[0][mat.size() - 2] << endl;
    return 0;
}