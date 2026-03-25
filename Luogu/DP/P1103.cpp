#include <bits/stdc++.h>
using namespace std;

int main()
{
    // --- 这里是为你补充的输入部分 ---
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> book(n);
    for (int i = 0; i < n; i++)
    {
        // pair 的 first 存高度，second 存宽度
        cin >> book[i].first >> book[i].second;
    }
    sort(book.begin(), book.end());
    vector<int> width;
    for (auto i : book)
    {
        width.push_back(i.second);
    }
    vector<vector<int>> dp(width.size() + 1, vector<int>(width.size()));
    // dp[i][j]表示，在前i本书，并且第i本书必选时候，选了j本书的最小差值和
    for (int i = 2; i <= width.size(); i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = 0X3F3F3F3F;
            for (int k = j; k < i; k++)
            {
                dp[i][j] = min(dp[k][j - 1] + abs(width[k - 1] - width[i - 1]), dp[i][j]);
            }
        }
    }
    int min_ = 0XFFFF;
    for (int i = width.size() - k; i < dp.size(); i++)
    {
        min_ = min(min_, dp[i][width.size() - k - 1]);
    }
    cout << min_ << endl;
}