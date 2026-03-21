#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    if (!(cin >> n))
        return 0; // 读取人数 N
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i]; // 读取每个人的身高
    }
    vector<int> dp_0(height.size());
    dp_0[0] = 1;
    for (int i = 1; i < dp_0.size(); i++)
    {
        int max_ = 1;
        for (int j = 0; j < i; j++)
        {
            if (height[j] < height[i])
            {
                max_ = max(max_, dp_0[j] + 1);
            }
        }
        dp_0[i] = max_;
    }
    vector<int> dp_1(height.size());
    dp_1[dp_1.size() - 1] = 1;
    for (int i = dp_1.size() - 2; i >= 0; i--)
    {
        int max_1 = 1;
        for (int j = dp_1.size() - 1; j > i; j--)
        {
            if (height[j] < height[i])
            {
                max_1 = max(max_1, dp_1[j] + 1);
            }
        }
        dp_1[i] = max_1;
    }
    int min_ = 0;
    for (int i = 0; i < dp_0.size(); i++)
    {
        min_ = max(min_, dp_0[i] + dp_1[i] - 1);
    }

    cout << height.size() - min_ << endl;
    return 0;
}