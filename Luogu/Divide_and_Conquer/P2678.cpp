#include <bits/stdc++.h>
using namespace std;

int check(const vector<int> &pos, int mid)
{
    int result = 0;
    int i = 0; // i 是当前站立的石头索引

    while (i < pos.size() - 1)
    { // 只要还没跳到终点
        int j = i + 1;
        // 内层循环：寻找从 i 出发，第一块距离 >= mid 的石头
        while (j < pos.size() && pos[j] - pos[i] < mid)
        {
            // 这块石头太近了，搬走它
            result++;
            j++;
        }

        // 这里的逻辑很关键：
        if (j < pos.size())
        {
            // 找到了合适的石头 j，直接跳过去
            i = j;
        }
        else
        {
            // 找遍了后面所有的石头（包括终点），竟然没有一个够远的！
            // 这说明此时 i 必须被搬走，或者 i 之后的石头全得搬走。
            // 由于 j 已经跑到了 pos.size()，while 循环已经帮我们计过数了。
            break;
        }
    }
    return result;
}

int main()
{
    int L, N, M;
    if (!(cin >> L >> N >> M))
        return 0;

    vector<int> pos(N + 2);
    pos[0] = 0;
    for (int i = 1; i <= N; i++)
        cin >> pos[i];
    pos[N + 1] = L;
    sort(pos.begin(), pos.end());

    int left = 1, right = L; // 距离最小是 1，最大是 L
    int ans = 0;

    // 标准二分模板，不需要递归，不需要特判
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (check(pos, mid) <= M)
        {
            ans = mid;      // mid 可行，先记下来
            left = mid + 1; // 尝试更大的距离
        }
        else
        {
            right = mid - 1; // mid 太大了，调小一点
        }
    }

    cout << ans << endl;
    return 0;
}