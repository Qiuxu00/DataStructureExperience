#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> height;
    int x;
    while (cin >> x)
    {
        height.push_back(x);
    }

    // 如果输入为空，直接退出
    if (height.empty())
        return 0;
    vector<int> dp(height.size());
    dp[height.size() - 1] = 1;
    for (int i = height.size() - 2; i > -1; i--)
    {
        int max_ = 1;
        for (int j = height.size() - 1; j > i; j--)
        {
            if (height[i] >= height[j])
            {
                max_ = max(max_, dp[j] + 1);
            }
        }
        dp[i] = max_;
    }
    int max_1 = 0;
    for (int i : dp)
    {
        if (i > max_1)
        {
            max_1 = i;
        }
    }
    cout << max_1 << endl;
    vector<int> dp_1(height.size());
    dp_1[0] = 1;
    for (int i = 1; i < height.size(); i++)
    {
        int max_ = 1;
        for (int j = 0; j < i; j++)
        {
            if (height[i] > height[j])
            {
                max_ = max(max_, dp_1[j] + 1);
            }
        }
        dp_1[i] = max_;
    }
    int max_2 = 0;
    for (int i : dp_1)
    {
        if (i > max_2)
        {
            max_2 = i;
        }
    }
    cout << max_2 << endl;
    return 0;
}