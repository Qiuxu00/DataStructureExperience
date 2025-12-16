#include <iostream>
#include <cmath>
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
int Level(Node<T> *Head, int level = 0)
{
    if (Head == nullptr)
    {
        return level;
    }
    level++;
    int L_height = Level(Head->l_child, level);
    int R_height = Level(Head->r_child, level);
    return max(L_height, R_height);
}

int main()
{
    // 手动构建二叉树
    //       1
    //      / \
    //     2   3
    //    /
    //   4
    Node<int> *root = new Node<int>(1);
    root->l_child = new Node<int>(2);
    root->r_child = new Node<int>(3);
    root->l_child->l_child = new Node<int>(4);

    BTree<int> tree(root);

    // 测试 Level 函数
    cout << "Tree Height: " << Level(tree.get_head()) << endl;

    return 0;
    return 0;
}