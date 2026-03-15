#include <bits/stdc++.h>
using namespace std;

long long nums(vector<vector<long long>> &vec, vector<vector<bool>> &ready, int X, int Y)
{
    if (ready[X][Y])
    {
        return vec[X][Y];
    }
    if (Y - 1 >= 0)
    {
        vec[X][Y] += nums(vec, ready, X, Y - 1);
    }
    if (X - 1 >= 0)
    {
        vec[X][Y] += nums(vec, ready, X - 1, Y);
    }
    ready[X][Y] = 1;
    return vec[X][Y];
}

int main()
{
    int b_x, b_y, m_x, m_y;
    // 读入：终点坐标 (b_x, b_y)，马的坐标 (m_x, m_y)
    if (!(cin >> b_x >> b_y >> m_x >> m_y))
        return 0;

    // 数组大小开到 b_x + 1，保证能访问到下标 b_x
    vector<vector<long long>> vec(b_x + 1, vector<long long>(b_y + 1, 0));
    vector<vector<bool>> ready(b_x + 1, vector<bool>(b_y + 1, false));

    // 马的控制点偏移量（包括马自身 0,0）
    int dx[] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 9; i++)
    {
        int nx = m_x + dx[i];
        int ny = m_y + dy[i];

        // 只有在棋盘范围内的马控制点才需要标记
        if (nx >= 0 && nx <= b_x && ny >= 0 && ny <= b_y)
        {
            ready[nx][ny] = true; // 标记为“已准备好”
            vec[nx][ny] = 0;      // 路径数为 0，意味着此路不通
        }
    }

    // 特判：如果起点就被马占了，那一条路都没有
    if (ready[0][0])
    {
        cout << 0 << endl;
    }
    else
    {
        // 初始化起点：路径数为 1，状态为已计算
        ready[0][0] = true;
        vec[0][0] = 1;
        cout << nums(vec, ready, b_x, b_y) << endl;
    }
    return 0;
}