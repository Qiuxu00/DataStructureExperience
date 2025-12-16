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
Node<T> *Build_help(int VLR[], int LVR[], int left_flag, int right_flag, int left_flag_VLR, int right_flag_LVR)
{

    if (left_flag == right_flag)
    {
        return new Node<T>(LVR[left_flag]);
    }
    int search = left_flag;

    for (; search <= right_flag; search++)
    {
        if (LVR[search] == VLR[left_flag_VLR])
        {
            break;
        }
    }
    int bias_l = search - left_flag;
    int bias_r = right_flag - search;
    Node<T> *ROOT = new Node<T>(LVR[search]);
    ROOT->l_child = Build_help<T>(VLR, LVR, left_flag, search - 1, left_flag_VLR + 1, left_flag_VLR + bias_l);
    ROOT->r_child = Build_help<T>(VLR, LVR, search + 1, right_flag, right_flag_LVR - bias_r + 1, right_flag_LVR);
    return ROOT;
}

template <class T>
Node<T> *Build(int VLR[], int LVR[], int size)
{
    return Build_help<T>(VLR, LVR, 0, size - 1, 0, size - 1);
}

// ======================
// 打印函数
// ======================
template <class T>
void print_pre(Node<T> *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    print_pre(root->l_child);
    print_pre(root->r_child);
}

template <class T>
void print_in(Node<T> *root)
{
    if (!root)
        return;
    print_in(root->l_child);
    cout << root->val << " ";
    print_in(root->r_child);
}

template <class T>
void print_post(Node<T> *root)
{
    if (!root)
        return;
    print_post(root->l_child);
    print_post(root->r_child);
    cout << root->val << " ";
}

// ======================
// main 测试代码
// ======================
int main()
{

    // 测试用例
    // 树结构（示例）：
    //        1
    //      /   \
    //     2     3
    //    / \
    //   4   5
    //
    // 前序: 1 2 4 5 3
    // 中序: 4 2 5 1 3

    int VLR[] = {1, 2, 4, 5, 3}; // 前序
    int LVR[] = {4, 2, 5, 1, 3}; // 中序
    int size = 5;

    Node<int> *root = Build<int>(VLR, LVR, size);

    cout << "构造出的树前序遍历: ";
    print_pre(root);
    cout << endl;

    cout << "构造出的树中序遍历: ";
    print_in(root);
    cout << endl;

    cout << "构造出的树后序遍历: ";
    print_post(root);
    cout << endl;

    return 0;
}