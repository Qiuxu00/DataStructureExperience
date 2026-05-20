#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    std::vector<int> parent;

    // 初始化：分配空间并让每个节点的父节点指向自己
    DSU(int n)
    {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
    }

    // 核心：带路径压缩的查找
    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // 路径压缩
    }

    // 合并：如果属于同一个集合返回 false，成功合并返回 true
    bool unite(int i, int j)
    {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i == root_j)
        {
            return false; // 已经连通，说明这条边会形成环！
        }

        parent[root_i] = root_j; // 随缘合并：直接把一棵树挂到另一棵树上
        return true;             // 成功合并，这条边可以选
    }
};

void solve(vector<int> &res)
{
    int n;
    int E;
    cin >> n >> E;
    vector<vector<int>> Edge(E, vector<int>(3));
    for (int i = 0; i < E; i++)
    {
        cin >> Edge[i][0] >> Edge[i][1] >> Edge[i][2];
    }
    if (E < n - 1)
    {
        res.push_back(-1);
        return;
    }
    int result = 0;
    sort(Edge.begin(), Edge.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });
    int ptr = 0;
    DSU d_1(n + 1);
    while (ptr < E)
    {
        if (d_1.find(Edge[ptr][0] - 1) != d_1.find(Edge[ptr][1] - 1))
        {
            d_1.unite(Edge[ptr][0] - 1, Edge[ptr][1] - 1);
            result += Edge[ptr][2];
            ptr++;
        }
        else
        {
            ptr++;
        }
    }
    int cur = 1;
    bool flag = true;
    while (cur < n)
    {
        if (d_1.find(0) != d_1.find(cur))
        {
            flag = false;
            break;
        }
        cur++;
    }
    if (flag)
    {
        res.push_back(result);
    }
    else
    {
        res.push_back(-1);
    }
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