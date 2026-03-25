#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> A = {0, 2, 5, 9, 14, 15};
    int p = 1;
    vector<vector<int>> dp(A.size(), vector<int>(A.size()));
    for (int step = 2; step < A.size(); step++)
    {
        for (int start = 0; start < A.size() - step; start++)
        {
            dp[start][start + step] = 0X3F3F3F3F;
            for (int k = start + 1; k < start + step; k++)
            {
                dp[start][start + step] = min(dp[start][start + step], dp[start][k] + dp[k][start + step] + p * (A[start + step] - A[start]));
            }
        }
    }
    cout << dp[0][dp[0].size() - 1] << endl;
    return 0;
}