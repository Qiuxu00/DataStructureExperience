#include <iostream>
#include <vector>
using namespace std;

enum Last
{
    Y,
    N
};

class Node
{
public:
    Last ever = N;
    int Number = -1;
    Node(int number) : Number(number) {}
};
class List_node
{
public:
    Node *node = nullptr;
    List_node *next = nullptr;
    List_node(Node *cur) : node(cur)
    {
    }
};
class List
{
public:
    List_node *head_ = nullptr;
    List(List_node *Head) : head_(Head)
    {
    }
    List() {}
    void push(List_node *temp)
    {
        List_node *Temp = head_;
        head_ = temp;
        temp->next = Temp;
    }

    void Delete(List_node *cur)
    {
        if (cur != nullptr)
        {
            List_node *temp = cur->next;
            delete cur;
            Delete(temp);
        }
        else
        {
            return;
        }
    }
    ~List()
    {
        Delete(head_);
    }
};

class Map
{
public:
    vector<List *> vertex_;
};

class Pair_c
{
public:
    int node = 0;
    int length = 0XFFFFFF;
    Last fix = N;
};

int Shortest(Map *map, int n)
{
    if (n == 1)
    {
        return 0;
    }
    vector<Pair_c> Table(n);
    int start = 1;
    int count = 0;
    Table[0].length = 0;
    while (Table[n - 1].fix != Y)
    {

        List_node *cur = map->vertex_[start - 1]->head_;
        while (cur != nullptr)
        {
            if (Table[cur->node->Number].length > Table[start - 1].length + 1 && Table[cur->node->Number].fix == N)
            {
                Table[cur->node->Number].node = start;
                Table[cur->node->Number].length = Table[start - 1].length + 1;
            }
            cur = cur->next;
        }
        int min = 0XFFFFFFF;
        int min_num = -1;
        int i = 0;
        int count1 = count;
        for (; i < Table.size(); i++)
        {
            if (Table[i].fix == N && Table[i].length < min)
            {
                count++;
                min = Table[i].length;
                min_num = i;
            }
        }
        if (count1 == count)
        {
            return -1;
        }
        start = min_num + 1;
        Table[min_num].fix = Y;
    }
    return Table[n - 1].length;
}
int main()
{
    int n = 5; // 节点总数 1 到 5
    Map g;

    // 1. 初始化节点池和邻接表
    // 这里的 vertex_ 下标 0 对应 节点 1，下标 4 对应 节点 5
    // Node 的 Number 属性必须存储对应的下标 (0 到 n-1)
    vector<Node *> node_pool;
    for (int i = 0; i < n; i++)
    {
        g.vertex_.push_back(new List());  // 为每个顶点分配链表
        node_pool.push_back(new Node(i)); // 创建节点，Number设为下标 0, 1, 2, 3, 4
    }

    // 2. 构建图
    // 场景：从 1 到 5。

    // 路径 A: 1->2->3->4->5 (距离为 4)
    // 对应下标关系：0->1, 1->2, 2->3, 3->4
    g.vertex_[0]->push(new List_node(node_pool[1]));
    g.vertex_[1]->push(new List_node(node_pool[2]));
    g.vertex_[2]->push(new List_node(node_pool[3]));
    g.vertex_[3]->push(new List_node(node_pool[4]));

    // 路径 B (捷径): 1->5 (距离为 1)
    // 对应下标关系：0->4
    // 注意：push 是头插法，所以这个捷径会被放在链表头部，算法会先处理它
    g.vertex_[0]->push(new List_node(node_pool[4]));

    // 3. 调用算法
    cout << "正在计算 1 号节点到 " << n << " 号节点的最短路径..." << endl;

    // 预期结果：应该走捷径 1->5，长度为 1
    int result = Shortest(&g, n);

    cout << "最短路径长度: " << result << endl;

    if (result == 1)
    {
        cout << "测试成功！" << endl;
    }
    else
    {
        cout << "测试失败。" << endl;
    }

    // 简单的内存清理（防止测试时内存泄漏，非必须但推荐）
    for (auto list : g.vertex_)
        delete list;
    for (auto node : node_pool)
        delete node;

    return 0;
}