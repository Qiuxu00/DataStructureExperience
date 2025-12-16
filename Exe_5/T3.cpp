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
void VLR(Node<T> *Head)
{
    if (Head == nullptr)
    {
        return;
    }
    cout << Head->val << " ";
    VLR(Head->l_child);
    VLR(Head->r_child);
}
template <class T>
void Invert(Node<T> *root)
{
    if (root == nullptr)
    {
        return;
    }
    Node<T> *temp = root->r_child;
    root->r_child = root->l_child;
    root->l_child = temp;
    Invert(root->l_child);
    Invert(root->r_child);
}

int main()
{
    // ¹¹Ôì¶þ²æÊ÷
    //       1
    //     /   \
    //    2     3
    //   / \   /
    //  4   5 6
    Node<int> *root = new Node<int>(1);
    root->l_child = new Node<int>(2);
    root->r_child = new Node<int>(3);
    root->l_child->l_child = new Node<int>(4);
    root->l_child->r_child = new Node<int>(5);
    root->r_child->l_child = new Node<int>(6);

    BTree<int> tree(root);

    cout << "Original Preorder: ";
    VLR(tree.get_head());
    cout << endl;

    Invert(tree.get_head());

    cout << "After Invert Preorder: ";
    VLR(tree.get_head());
    cout << endl;

    return 0;
}