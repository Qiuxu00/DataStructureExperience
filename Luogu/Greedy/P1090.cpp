#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int weight;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int w) : weight(w) {}
    ~Node()
    {
        delete left;
        delete right;
    }
};
struct Compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->weight > r->weight;
    }
};

Node *buildHuffmanTree(const std::vector<int> &weights)
{
    if (weights.empty())
        return nullptr;

    // 1. 初始化最小堆
    std::priority_queue<Node *, std::vector<Node *>, Compare> minHeap;
    for (int w : weights)
    {
        minHeap.push(new Node(w));
    }

    // 2. 迭代合并
    while (minHeap.size() > 1)
    {
        // 取出两个最小的节点
        Node *left = minHeap.top();
        minHeap.pop();

        Node *right = minHeap.top();
        minHeap.pop();

        // 创建父节点
        Node *parent = new Node(left->weight + right->weight);
        parent->left = left;
        parent->right = right;

        // 将新节点放回堆
        minHeap.push(parent);
    }

    // 3. 返回根节点
    return minHeap.top();
}

void rec(Node *cur, int &sum)
{
    if (cur->left == nullptr || cur->right == nullptr)
    {
        return;
    }
    else
    {
        sum += cur->weight;
        rec(cur->left, sum);
        rec(cur->right, sum);
    }
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    // 2. 循环读取每堆果子的数量并存入 vector
    vector<int> fruits(n);
    for (int i = 0; i < n; i++)
    {
        cin >> fruits[i];
    }
    int sum = 0;
    Node *head = buildHuffmanTree(fruits);
    rec(head, sum);
    cout << sum << endl;
    delete head;
    return 0;
}