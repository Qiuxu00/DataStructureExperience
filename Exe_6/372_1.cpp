#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
public:
    int to;
    double weights;
    Edge(int T, double W) : to(T), weights(W) {}
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
            head_[from].push_back(Edge(to, weight));
            head_[to].push_back(Edge(from, weight));
        }
    }
};

void Shortes(Graph *graph, int v)
{
    vector<bool> ever(graph->n, false);
    vector<double> result(graph->n, 0);
    queue<int> node;
    node.push(v);
    ever[v] = true;
    do
    {
        int V = node.front();
        node.pop();
        for (auto i : graph->head_[V])
        {
            if (ever[i.to] == false)
            {
                node.push(i.to);
                ever[i.to] = true;
                result[i.to] = result[V] + i.weights;
            }
        }

    } while (!node.empty());
    for (int i = 0; i < result.size(); i++)
    {
        cout << "从" << v << " 到 " << i << " 的最短距离是 " << result[i] << endl;
    }
}
// --- 测试用的 Main 函数 ---
int main()
{
    // 1. 创建一个有 5 个节点 (0~4) 的图
    int nodeCount = 5;
    Graph myTree(nodeCount);

    cout << "正在构建树结构..." << endl;

    /* 构建如下树结构：
             0
           /   \
          1     2
         / \
        3   4

       边权设置：
       0-1: 2.0
       0-2: 5.5
       1-3: 1.0
       1-4: 3.0
    */

    // 注意：输入编号都是从 0 开始
    myTree.addEdge(0, 1, 2.0);
    myTree.addEdge(0, 2, 5.5);
    myTree.addEdge(1, 3, 1.0);
    myTree.addEdge(1, 4, 3.0);

    // 2. 调用函数计算从 0 号节点出发的距离
    Shortes(&myTree, 0);

    // 预期输出：
    // 到 0: 0
    // 到 1: 2
    // 到 2: 5.5
    // 到 3: 3 (2+1)
    // 到 4: 5 (2+3)

    return 0;
}
