#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {3, 2, 1, 4, 5};
    vector<vector<int>> dp(A.size(), vector<int>(B.size()));
    dp[0][0] = (A[0] == B[0]); // which means when comes to A[i] and B[j] ,the longest partten's length
    bool flag = 0;
    for (int i = 0; i < B.size(); i++)
    {
        if (A[0] == B[i])
        {
            flag = 1;
        }
        dp[0][i] = flag;
    }
    flag = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == B[0])
        {
            flag = 1;
        }
        dp[i][0] = flag;
    }
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 1; j < B.size(); j++)
        {

            if (A[i] == B[j])
            {
                dp[i][j] = max({dp[i - 1][j - 1] + 1, dp[i][j - 1], dp[i - 1][j]});
            }
            else
            {
                dp[i][j] = max({dp[i][j - 1], dp[i - 1][j]});
            }
        }
    }
    cout << dp[A.size() - 1][B.size() - 1] << endl;
    return 0;
}