#include <bits/stdc++.h>
using namespace std;

int main()
{ // --- 1. 修改后的 Input 部分 ---
    int N;
    if (!(cin >> N))
        return 0;

    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    // 读取三角形矩阵到 con
    vector<vector<int>> con(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            int temp;
            cin >> temp;
            con[i].push_back(temp);
        }
    }
    vector<int> dp(N, 0);

    vector<int> pre(N);
    for (int i = 0; i < N - 1; i++)
    {
        con[i].resize(N - i - 1);
    }
    dp[0] = nums[0];
    pre[0] = 0;
    for (int i = 1; i < N; i++)
    {
        dp[i] = nums[i];
        pre[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (con[j][i - j - 1])
            {
                if (dp[j] + nums[i] > dp[i])
                {
                    pre[i] = j;
                    dp[i] = dp[j] + nums[i];
                }
            }
        }
    }

    int start = N - 1;
    int max_ = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        if (dp[i] > max_)
        {
            max_ = dp[i];
            start = i;
        }
    }
    int s = start;
    stack<int> st;
    st.push(start);
    while (pre[start] != start)
    {
        st.push(pre[start]);
        start = pre[start];
    }
    while (!st.empty())
    {
        cout << st.top() + 1 << " ";
        st.pop();
    }
    cout << endl;
    cout << dp[s] << endl;

    return 0;
}