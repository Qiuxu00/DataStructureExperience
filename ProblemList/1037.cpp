#include <bits/stdc++.h>
using namespace std;

class Dinic
{
public:
    struct Edge
    {
        int to;
        long long cap;
        int rev;
    };
    vector<vector<Edge>> adj;
    vector<int> level;
    vector<int> ptr;
    Dinic(int n) : adj(n), level(n), ptr(n) {}

    // 添加边：
    void add_edge(int from, int to, int cap)
    {
        adj[from].push_back({to, cap, (int)adj[to].size()});
        adj[to].push_back({from, 0, (int)adj[from].size() - 1});
    }

    bool bfs(int s, int t)
    {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto &edge : adj[v])
            {
                if (edge.cap > 0 && level[edge.to] == -1)
                {
                    level[edge.to] = level[v] + 1;
                    q.push(edge.to);
                }
            }
        }
        return level[t] != -1;
    }

    // DFS 寻找增广路
    long long dfs(int v, int t, long long pushed)
    {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;

        for (int &cid = ptr[v]; cid < adj[v].size(); ++cid)
        {
            auto &edge = adj[v][cid];
            int tr = edge.to;
            if (level[v] + 1 != level[tr] || edge.cap == 0)
                continue;

            long long tr_pushed = dfs(tr, t, min(pushed, edge.cap));
            if (tr_pushed == 0)
                continue;

            edge.cap -= tr_pushed;
            adj[tr][edge.rev].cap += tr_pushed;
            return tr_pushed;
        }
        return 0;
    }

    // 计算最大流
    long long max_flow(int s, int t)
    {
        long long flow = 0;
        while (bfs(s, t))
        {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, t, 1e18))
            { // 使用足够大的初始流量
                flow += pushed;
            }
        }
        return flow;
    }
};

void solve(vector<long long> &res)
{
    int n, m;
    cin >> n >> m;
    Dinic din(n + m + 2);
    vector<vector<int>> man(n);
    int s = 0;
    int t = n + m + 1;
    for (int i = 0; i < n; i++)
    {
        int N;
        cin >> N;
        man[i].resize(N);
        for (int &k : man[i])
        {
            cin >> k;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        din.add_edge(s, i, 1);
    }

    // 2. 每个男嘉宾连向他中意的女嘉宾，容量为 1
    for (int i = 0; i < n; i++)
    {
        for (int fem_id : man[i])
        {
            // 男嘉宾 i+1 连向女嘉宾 n + fem_id
            din.add_edge(i + 1, n + fem_id, 1);
        }
    }

    // 3. 所有女嘉宾连向汇点 T，容量为 1
    for (int j = 1; j <= m; j++)
    {
        din.add_edge(n + j, t, 1);
    }
    res.push_back(din.max_flow(s, t));
}
int main()
{
    int n;
    cin >> n;
    vector<long long> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (auto i : res)
    {
        cout << i << endl;
    }
    return 0;
}