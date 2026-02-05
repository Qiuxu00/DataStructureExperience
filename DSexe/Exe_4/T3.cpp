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
            if (temp != nullptr)
            {
                delete temp;
            }
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
Node<T> *cross_node(Node<T> *headA, Node<T> *headB)
{
    Node<T> *cur_A = headA->next;
    Node<T> *cur_B = headB->next;
    int count_a = 0;
    int count_b = 0;
    while (cur_A != nullptr || cur_B != nullptr)
    {
        if (cur_A != nullptr)
        {
            count_a++;
            cur_A = cur_A->next;
        }
        if (cur_B != nullptr)
        {
            count_b++;
            cur_B = cur_B->next;
        }
    }
    Node<T> *ptr_a = headA;
    Node<T> *ptr_b = headB;
    int bias;
    count_a > count_b ? bias = count_a - count_b : bias = count_b - count_a;
    if (count_a > count_b)
    {
        for (int i = 0; i < bias; i++)
        {
            ptr_a = ptr_a->next;
        }
    }
    else
    {
        for (int i = 0; i < bias; i++)
        {
            ptr_b = ptr_b->next;
        }
    }
    Node<T> *Flag = nullptr;
    while (ptr_a != nullptr)
    {
        if (ptr_a != ptr_b)
        {
            Flag = nullptr;
        }
        if (Flag == nullptr && ptr_a == ptr_b)
        {
            Flag = ptr_a;
        }
        ptr_a = ptr_a->next;
        ptr_b = ptr_b->next;
    }
    return Flag;
}

int main()
{
    List<int> LstA;
    List<int> LstB;
    Node<int> *a1 = new Node<int>(1);
    Node<int> *a2 = new Node<int>(2);
    Node<int> *a3 = new Node<int>(3);
    Node<int> *b1 = new Node<int>(4);
    Node<int> *b2 = new Node<int>(5);

    LstA.get_head()->next = a1;
    a1->next = a2;
    a2->next = a3;
    LstB.get_head()->next = b1;
    b1->next = b2;

    Node<int> *cross = new Node<int>(10);
    a3->next = cross;
    b2->next = cross;
    Node<int> *both_1 = new Node<int>(11);
    Node<int> *both_2 = new Node<int>(12);
    cross->next = both_1;
    both_1->next = both_2;
    Node<int> *cur = LstA.get_head()->next;
    while (cur != nullptr)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    cur = LstB.get_head()->next;
    while (cur != nullptr)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    cout << "The first cross node is " << cross_node(LstA.get_head(), LstB.get_head())->val << endl;
    a3->next = nullptr;

    return 0;
}