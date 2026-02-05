#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next = nullptr;
    pair<double, int> val;
    Node(double d, int i) : val(d, i)
    {
    }
};

class List_pair
{

public:
    Node *head_ = nullptr;
    List_pair()
    {
        head_ = new Node(0, 0);
    }

    void insert(Node *n_prev, Node *n_in)
    {
        Node *next = n_prev->next;
        n_prev->next = n_in;
        n_in->next = next;
    }
};

void test(List_pair l_1, List_pair l_2)
{
    Node *p_1 = l_1.head_->next;
    Node *p_2 = l_2.head_->next;
    Node *new_start = p_1->val.second > p_2->val.second ? l_2.head_->next : l_1.head_->next;
    while (p_1 != nullptr && p_2 != nullptr)
    {
    }
}

int main()
{
    pair<double, int> p1[] = {};
    pair<double, int> p2[] = {};

    return 0;
}
