#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

void Quicksort(vector<Edge> *vec, int L, int R)
{
    if (L >= R)
    {
        return;
    }
    int Left = L, Right = R;
    auto temp = (*vec)[L];
    while (L < R)
    {
        while (L < R && (*vec)[R].weights >= temp.weights)
        {
            R--;
        }
        while (L < R && (*vec)[L].weights <= temp.weights)
        {
            L++;
        }
        if (L < R)
        {
            swap((*vec)[L], (*vec)[R]);
        }
    }
    swap((*vec)[Left], (*vec)[L]);
    Quicksort(vec, Left, R - 1);
    Quicksort(vec, R + 1, Right);
}

class Union_Search
{
public:
    vector<int> parent;
    int n;
    Union_Search(int N) : n(N)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find_p(int v)
    {
        return parent[v] == v ? v : parent[v] = find_p(parent[v]);
    }
    bool is_connect(int y, int x)
    {
        return find_p(x) == find_p(y);
    }
    void unite(int i, int j)
    {
        parent[find_p(i)] = find_p(j);
    }
};

void minSpanningTree(Graph *g)
{
    double sum = 0;
    vector<Edge> SpanningTree;
    vector<Edge> SortedEdge;
    for (auto i : g->head_)
    {
        for (auto ii : i)
        {
            SortedEdge.push_back(ii);
        }
    }
    Quicksort(&SortedEdge, 0, SortedEdge.size() - 1);
    Union_Search set_1(g->n);
    for (auto i : SortedEdge)
    {
        if (!set_1.is_connect(i.from, i.to))
        {
            SpanningTree.push_back(i);
            set_1.unite(i.from, i.to);
            sum += i.weights;
        }
    }
    cout << "最小生成树权重之和是: " << sum << endl;
}

int main()
{
    // 创建一个有 4 个顶点的图 (0, 1, 2, 3)
    Graph g(4);

    // 添加边 (起点, 终点, 权重)
    // 这里的例子是一个经典的测试图
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    // 理论上的最小生成树应该是：
    // 1. 选边 2-3 (权重4)
    // 2. 选边 0-3 (权重5)
    // 3. 选边 0-1 (权重10) -> 注意：此时0和3连通，1和3连通，所以0-1把1接进来
    // 1-3 (权重15) 会形成环，跳过
    // 0-2 (权重6) 会形成环，跳过
    // 总权重应为：4 + 5 + 10 = 19

    minSpanningTree(&g);

    return 0;
}