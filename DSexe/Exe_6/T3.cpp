#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

class Edge
{
public:
    int to;
    int from;
    double weights;
    Edge(int T, double W, int F) : to(T), weights(W), from(F) {}
};

class Graph
{
public:
    int n;
    vector<vector<Edge>> head_;
    Graph(int N) : n(N)
    {
        head_.resize(n);
    }
    void addEdge(int from, int to, double weight)
    {
        bool flag = true;
        for (auto i : head_[from])
        {
            if (to == i.to)
            {
                flag = false;
                return;
            }
        }
        for (auto i : head_[to])
        {
            if (from == i.to)
            {
                flag = false;
                return;
            }
        }
        if (flag)
        {
            head_[from].push_back(Edge(to, weight, from));
            head_[to].push_back(Edge(from, weight, to));
        }
    }
};

double Dijkstra(Graph *g)
{
    if (g->n <= 1)
    {
        return 0;
    }
    unordered_map<int, bool> fixed;
    vector<double> final(g->n, __DBL_MAX__);
    final[0] = 0;
    int start = 0;
    while (fixed[g->n - 1] == false)
    {
        bool flag = false;
        fixed[start] = true;
        for (auto i : g->head_[start])
        {
            if (fixed[i.to] == false && final[i.to] > final[start] + i.weights)
            {
                final[i.to] = final[start] + i.weights;
            }
        }
        double min = __DBL_MAX__;
        int minnumber;
        for (int i = 0; i < g->n; i++)
        {
            if (fixed[i] == false && final[i] < min)
            {
                flag = true;
                min = final[i];
                minnumber = i;
            }
        }
        if (!flag && fixed[g->n - 1] == false)
        {
            return -1;
        }
        start = minnumber;
    }
    return final[g->n - 1];
}

// ... (你的上面的类和函数代码保持不变) ...

void runTest(string testName, Graph *g, double expectedResult)
{
    cout << "Running " << testName << "..." << endl;
    double result = Dijkstra(g);

    cout << "  预期结果: " << expectedResult << endl;
    cout << "  实际结果: " << result << endl;

    // 简单的浮点数比对（考虑到-1的情况）
    if (abs(result - expectedResult) < 1e-6)
    {
        cout << "  >>> 测试通过 ✅" << endl;
    }
    else
    {
        cout << "  >>> 测试失败 ❌" << endl;
    }
    cout << "----------------------------------" << endl;
}

int main()
{
    // ==========================================
    // 测试用例 1: 标准连通图 (寻找 0 到 3 的最短路)
    // ==========================================
    // 拓扑结构：
    // 0 -> 1 (权重 10)
    // 0 -> 2 (权重 5)
    // 1 -> 3 (权重 20)
    // 2 -> 3 (权重 10)
    // 2 -> 1 (权重 2)
    //
    // 理论最短路径: 0 -> 2 -> 1 -> 3
    // 路径计算: 5 + 2 + 20 = 27 (不对，直接走2-3更短)
    // 路径计算: 0 -> 2 -> 3 = 5 + 10 = 15
    // 路径计算: 0 -> 1 -> 3 = 10 + 20 = 30
    // 最短应该是 15.

    Graph g1(4);
    g1.addEdge(0, 1, 10);
    g1.addEdge(0, 2, 5);
    g1.addEdge(1, 3, 20);
    g1.addEdge(2, 3, 10);
    g1.addEdge(2, 1, 2); // 这条边让图变得稍微复杂一点

    runTest("测试 1 (标准路径)", &g1, 15.0);

    // ==========================================
    // 测试用例 2: 不连通图 (断路测试)
    // ==========================================
    // 0 和 1 连通，2 和 3 连通。但是 (0,1) 这一组和 (2,3) 这一组断开。
    // 目标是从 0 走到 3。

    Graph g2(4);
    g2.addEdge(0, 1, 5);
    g2.addEdge(2, 3, 5);
    // 没有连接 0/1 到 2/3 的边

    runTest("测试 2 (不连通图)", &g2, -1.0);

    // ==========================================
    // 测试用例 3: 只有 1 个点的图 (边界情况)
    // ==========================================
    // 起点也是终点，距离应为 0

    Graph g3(1);

    runTest("测试 3 (单点图)", &g3, 0.0);

    return 0;
}