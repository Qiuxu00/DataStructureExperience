#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
// 1. 定义节点结构
struct TreeNode
{
    int data;
    TreeNode *left, *right;

    // 构造函数初始化
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 2. 二叉搜索树类封装
class BinaryTree
{
private:
    TreeNode *root;

    // 内部递归插入函数 (定性：利用递归回溯连接节点)
    TreeNode *insertRecursive(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return new TreeNode(val);
        }
        if (val < node->data)
        {
            node->left = insertRecursive(node->left, val);
        }
        else
        {
            node->right = insertRecursive(node->right, val);
        }
        return node;
    }

    // 内部递归销毁函数 (定性：必须使用后序遍历，确保安全删除)
    void destroyTree(TreeNode *node)
    {
        if (node)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    // 中序遍历 (L-Root-R)
    void inOrder(TreeNode *node)
    {
        if (node == nullptr)
            return;
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree()
    {
        destroyTree(root);
    }

    void insert(int val)
    {
        root = insertRecursive(root, val);
    }

    void displayInOrder()
    {
        inOrder(root);
        std::cout << std::endl;
    }

    int height()
    {
        int height = 0;
        queue<TreeNode *> q_1;
        queue<TreeNode *> q_2;
        if (root)
        {
            q_1.push(root);
        }
        else
        {
            return 0;
        }
        while (!q_1.empty())
        {
            auto cur = q_1.front();
            q_1.pop();
            if (cur->left)
            {
                q_2.push(cur->left);
            }
            if (cur->right)
            {
                q_2.push(cur->right);
            }
            if (q_1.empty())
            {
                height++;
                swap(q_1, q_2);
            }
        }
        return height;
    }
};

// 3. 测试示例
int main()
{
    BinaryTree bst;

    // 插入定量分析：插入 5 个节点
    std::vector<int> nodes = {5, 3, 7, 2, 4};
    for (int val : nodes)
    {
        bst.insert(val);
    }

    std::cout << "BST In-order Traversal (Should be sorted): " << std::endl;
    bst.displayInOrder();
    cout << bst.height() << endl;

    return 0;
}