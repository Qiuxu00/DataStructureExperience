#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 将左右端点绑定在一起
struct Interval
{
    double left;
    double right;
};

// 核心：按右端点从小到大排序
bool compareInterval(const Interval &a, const Interval &b)
{
    return a.right < b.right;
}

void solve()
{
    int n;
    double d;
    cin >> n >> d;

    vector<Interval> intervals;

    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        // 如果纵坐标大于雷达半径，直接不可能覆盖（部分题目可能有此坑，此题若保证有解可忽略）
        if (y <= d)
        {
            double offset = sqrt(d * d - y * y);
            intervals.push_back({x - offset, x + offset});
        }
    }

    // 对整体区间排序
    sort(intervals.begin(), intervals.end(), compareInterval);

    int result = 0;
    double last_pos = -1e20; // 记录上一个基站的放置位置，初始化为极小值
    double limit = 1e-7;     // 应对浮点数精度误差的容差值

    for (const auto &interval : intervals)
    {
        // 如果当前区间的左端点严格大于上一个基站的位置（考虑精度误差），说明未被覆盖
        if (interval.left > last_pos + limit)
        {
            result++;
            last_pos = interval.right; // 贪心：基站放置在当前区间的右侧尽头
        }
    }

    cout << result << "\n";
}

int main()
{
    // 优化cin/cout速度，防止数据量大时超时
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    if (cin >> m)
    {
        while (m--)
        {
            solve();
        }
    }
    return 0;
}