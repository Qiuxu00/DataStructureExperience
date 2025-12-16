#include <iostream>
using namespace std;

template <class T>
class Node
{

public:
    T val;
    Node<T> *l_child = nullptr;
    Node<T> *r_child = nullptr;
    Node(T Val) : val(Val)
    {
    }
};

template <class T>
class BTree
{
    Node<T> *head_;

public:
    BTree(Node<T> *Head) : head_(Head)
    {
    }
    ~BTree()
    {
        delete_btree(head_);
    }
    void delete_btree(Node<T> *Head)
    {
        if (Head == nullptr)
        {
            return;
        }
        Node<T> *Left = Head->l_child;
        Node<T> *Right = Head->r_child;
        delete Head;
        delete_btree(Left);
        delete_btree(Right);
    }
    Node<T> *get_head()
    {
        return head_;
    }
};

template <class T>
void flatten(Node<T> *node, Node<T> *&prev)
{
    if (!node)
        return;

    if (prev) // 这一块一定要细看
    {
        prev->r_child = node;
        prev->l_child = nullptr;
    }
    prev = node; // 重置前驱指针

    Node<T> *left = node->l_child;
    Node<T> *right = node->r_child;

    flatten(left, prev);
    flatten(right, prev);
}

template <class T>
Node<T> *VLR(Node<T> *root)
{
    Node<T> *prev = nullptr;
    flatten(root, prev);
    return root;
}

int main()
{
    // 构造树
    //         1
    //       /   \
    //      2     5
    //     / \     \
    //    3   4     6
    Node<int> *root = new Node<int>(1);
    root->l_child = new Node<int>(2);
    root->r_child = new Node<int>(5);
    root->l_child->l_child = new Node<int>(3);
    root->l_child->r_child = new Node<int>(4);
    root->r_child->r_child = new Node<int>(6);

    BTree<int> tree(root);

    cout << "Flattening tree..." << endl;
    VLR(tree.get_head());

    // 打印前序展开后的右链表
    Node<int> *cur = tree.get_head();
    cout << "Result (Right-chain view): ";
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->r_child;
    }
    cout << endl;

    return 0;
}