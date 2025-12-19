#include <iostream>
#include <algorithm> // for std::max

using namespace std;

// 1. 节点定义
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height; // 节点高度，叶子节点为 1

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
private:
    Node *root;

    // --- 辅助函数：获取高度 ---
    // 能够处理节点为 nullptr 的情况
    int getHeight(Node *N)
    {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    // --- 辅助函数：获取平衡因子 (Balance Factor) ---
    int getBalance(Node *N)
    {
        if (N == nullptr)
            return 0;
        return getHeight(N->left) - getHeight(N->right);
    }

    // --- 核心：右旋 (Right Rotate) ---
    // 对应 LL 型失衡
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        // 旋转
        x->right = y;
        y->left = T2;

        // 更新高度 (先更新子节点 y，再更新父节点 x)
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        // 返回新的根节点
        return x;
    }

    // --- 核心：左旋 (Left Rotate) ---
    // 对应 RR 型失衡
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        // 旋转
        y->left = x;
        x->right = T2;

        // 更新高度
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        // 返回新的根节点
        return y;
    }

    // --- 插入函数 (递归) ---
    Node *insert(Node *node, int key)
    {
        // 1. 执行正常的 BST 插入
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else // 不允许重复键值
            return node;

        // 2. 更新当前节点的高度
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // 3. 获取平衡因子，判断是否失衡
        int balance = getBalance(node);

        // 4. 如果失衡，进行旋转

        // 情况 1: LL 型 (左左) -> 右旋
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // 情况 2: RR 型 (右右) -> 左旋
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // 情况 3: LR 型 (左右) -> 先左旋再右旋
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // 情况 4: RL 型 (右左) -> 先右旋再左旋
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // 返回未变动或已平衡的节点指针
        return node;
    }

    // --- 删除辅助：找到最小值节点 ---
    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    // --- 删除函数 (递归) ---
    Node *remove(Node *root, int key)
    {
        // 1. 标准 BST 删除
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = remove(root->left, key);
        else if (key > root->key)
            root->right = remove(root->right, key);
        else
        {
            // 找到了要删除的节点
            // 情况 A: 只有一个子节点或没有子节点
            if ((root->left == nullptr) || (root->right == nullptr))
            {
                Node *temp = root->left ? root->left : root->right;

                // 无子节点情况
                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else               // 一个子节点情况
                    *root = *temp; // 复制内容

                delete temp;
            }
            else
            {
                // 情况 B: 有两个子节点
                // 获取右子树中的最小节点 (后继节点)
                Node *temp = minValueNode(root->right);

                // 将后继节点的值复制到当前节点
                root->key = temp->key;

                // 删除后继节点
                root->right = remove(root->right, temp->key);
            }
        }

        // 如果树只有一个节点，删除后为空，直接返回
        if (root == nullptr)
            return root;

        // 2. 更新高度
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // 3. 检查平衡
        int balance = getBalance(root);

        // 4. 失衡处理 (同插入，但判断条件略有不同，看 getBalance 而不是 key)

        // LL Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // LR Case
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // RR Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // RL Case
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // 中序遍历 (用于打印)
    void inOrder(Node *root)
    {
        if (root != nullptr)
        {
            inOrder(root->left);
            cout << root->key << " ";
            inOrder(root->right);
        }
    }

    // 销毁树
    void destroy(Node *node)
    {
        if (node)
        {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() { destroy(root); }

    void insert(int key)
    {
        root = insert(root, key);
    }

    void remove(int key)
    {
        root = remove(root, key);
    }

    void print()
    {
        inOrder(root);
        cout << endl;
    }
};

// --- 测试主函数 ---
int main()
{
    AVLTree tree;

    /* 构建一棵树
            30
           /  \
         20   40
        /  \    \
       10  25   50
    */
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "中序遍历 AVL 树: \n";
    tree.print(); // 输出应该是排序好的: 10 20 25 30 40 50

    cout << "删除 20 后: \n"; // 删除带两个子节点的非叶子节点
    tree.remove(20);
    tree.print();

    return 0;
}