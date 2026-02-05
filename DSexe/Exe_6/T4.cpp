#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

class Graph
{
public:
    int n;
    vector<pair<int, int>> EDGE;
    vector<int> In;
    Graph(int N) : n(N)
    {
        In.resize(n);
    }
    void add_edge(int from, int to)
    {
        pair<int, int> p(from, to);
        EDGE.push_back(p);
        In[to]++;
    }
};

void Order(Graph *g)
{
    queue<int> INOrder;
    vector<int> FinalResult;
    vector<int> In = g->In;
    vector<bool> Fixed(g->n);
    for (int i = 0; i < In.size(); i++)
    {
        if (In[i] == 0 && Fixed[i] == false)
        {
            INOrder.push(i);
            Fixed[i] = true;
        }
    }
    if (INOrder.empty())
    {
        cerr << "无前序课程" << endl;
        return;
    }
    do
    {
        int cur = INOrder.front();
        FinalResult.push_back(cur);
        INOrder.pop();
        for (auto i : g->EDGE)
        {
            if (i.first == cur)
            {
                In[i.second]--;
            }
        }
        for (int i = 0; i < In.size(); i++)
        {
            if (In[i] == 0 && Fixed[i] == false)
            {
                INOrder.push(i);
                Fixed[i] = true;
            }
        }
    } while (!INOrder.empty());
    cout << "正确的课程顺序是 ";
    for (int i = 0; i < FinalResult.size() - 1; i++)
    {
        cout << FinalResult[i] << "->";
    }
    cout << FinalResult[FinalResult.size() - 1];
    cout << endl;
}
// === 测试用的 Main 函数 ===

int main()
{
    cout << "============= 测试用例 1: 简单线性依赖 =============" << endl;
    // 场景：穿衣服 (0内裤 -> 1秋裤 -> 2裤子 -> 3鞋子)
    Graph g1(4);
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);
    Order(&g1);
    cout << endl;

    cout << "============= 测试用例 2: 复杂的课程先修关系 =============" << endl;
    /* 节点含义假设：
       0: 离散数学
       1: 算法设计
       2: 数据结构
       3: 进阶编程
       4: 线性代数
       5: 计算机导论

       依赖关系：
       5(导论) -> 2(数据结构)
       5(导论) -> 0(离散)
       4(线代) -> 0(离散)
       4(线代) -> 1(算法)
       2(数据结构) -> 3(进阶)
       3(进阶) -> 1(算法)
    */
    Graph g2(6);
    g2.add_edge(5, 2);
    g2.add_edge(5, 0);
    g2.add_edge(4, 0);
    g2.add_edge(4, 1);
    g2.add_edge(2, 3);
    g2.add_edge(3, 1);

    cout << "期望输出: 应该先输出 4 和 5 (基础课)，最后输出 1 (最难的课)" << endl;
    Order(&g2);
    cout << endl;

    cout << "============= 测试用例 3: 有环图 (死锁) =============" << endl;
    // 场景：A依赖B，B依赖A (0 -> 1 -> 0)
    // 还有一个孤立点 2
    Graph g3(3);
    g3.add_edge(0, 1);
    g3.add_edge(1, 0);

    // 2号点没有依赖，应该能输出
    cout << "图中存在 0->1->0 的环，只有点 2 能被处理：" << endl;
    Order(&g3);

    return 0;
}