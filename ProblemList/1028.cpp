#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &res)
{
    int n, E, s, t;
    cin >> n >> E >> s >> t;
    if (s == t)
    {
        res.push_back(0);
        return;
    }
    vector<vector<int>> Map(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < E; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;
        if (Map[from][to] == -1)
        {
            Map[from][to] = w;
            Map[to][from] = w;
            continue;
        }
        if (w < Map[from][to])
        {
            Map[from][to] = w;
            Map[to][from] = w;
        }
    }
    vector<int> length(n + 1, 1e9);
    vector<bool> fixed(n + 1, false);

    length[s] = 0;
    fixed[s] = true;

    int cur = s;

    while (cur != t)
    {
        // 更新路径当前最短长度并得到更新的节点
        int min_node_pos = 0;
        int min_l = __INT_MAX__;
        for (int i = 1; i < n + 1; i++)
        {
            if (!fixed[i] && Map[cur][i] != -1 && length[cur] + Map[cur][i] < length[i])
            {
                length[i] = length[cur] + Map[cur][i];
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            if (!fixed[i] && length[i] < min_l)
            {
                min_node_pos = i;
                min_l = length[i];
            }
        }
        // 如果没有节点被改变，说明已经走到尽头
        if (min_node_pos == 0)
        {
            res.push_back(-1);
            return;
        }

        // 更新图状态
        cur = min_node_pos;
        fixed[min_node_pos] = true;
    }
    res.push_back(length[t]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (int i : res)
    {
        cout << i << endl;
    }
    return 0;
}