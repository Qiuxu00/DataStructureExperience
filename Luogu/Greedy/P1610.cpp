#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, dist;
    if (!(cin >> n >> dist))
        return 0;
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
        cin >> pos[i];

    // 习惯性排个序，防止数据输入不规范
    sort(pos.begin(), pos.end());

    int result = 0;
    int pre = 0; // 记录上一盏“确定亮着”的灯的索引

    // 遍历中间的灯 (索引 1 到 n-2)
    for (int i = 1; i < n - 1; i++)
    {
        // 如果上一盏亮着的灯 和 下一盏灯 之间的距离够近
        if (pos[i + 1] - pos[pre] <= dist)
        {
            result++; // 这盏灯(i)可以关掉，不需要更新pre
        }
        else
        {
            pre = i; // 这盏灯(i)必须留着，成为新的基准点
        }
    }

    cout << result << endl;
    return 0;
}