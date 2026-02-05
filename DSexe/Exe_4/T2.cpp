#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    Node(T VAL) : val(VAL)
    {
    }
    T val;
    Node<T> *next = nullptr;
};

template <class T>
class List
{
    Node<T> *head_ = nullptr;

public:
    List()
    {
        head_ = new Node<T>(int(0));
    }
    ~List()
    {
        while (head_ != nullptr)
        {
            Node<T> *temp = head_;
            head_ = head_->next;
            delete temp;
        }
    }
    void push_back(T VAL)
    {
        Node<T> *cur = head_;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        Node<T> *now = new Node<T>(VAL);
        cur->next = now;
    }
    Node<T> *get_head()
    {
        return head_;
    }
};

template <typename T>
void invert_list(Node<T> *Head)
{
    if (Head->next == nullptr)
    {
        cout << "Invertion Complete" << endl;
        return;
    }

    Node<T> *ptr_f = Head->next->next;
    Node<T> *ptr_s = Head->next;
    ptr_s->next = nullptr;
    while (ptr_f != nullptr)
    {
        Node<T> *temp = ptr_f->next;
        ptr_f->next = ptr_s;
        ptr_s = ptr_f;
        ptr_f = temp;
    }
    Head->next = ptr_s;
}

int main()
{
    List<int> lst;
    int size = 10;
    for (int i = 0; i < size; i++)
    {
        lst.push_back(i + 1);
    }
    Node<int> *cur = lst.get_head()->next;
    while (cur != nullptr)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    invert_list(lst.get_head());
    cur = lst.get_head()->next;
    while (cur != nullptr)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    return 0;
}