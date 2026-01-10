#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    Node(int V = -1) : val(V)
    {
    }
    int val;
    Node *next_ = nullptr;
};
class list
{

public:
    Node *head_ = new Node();
    Node *tail_ = nullptr;
    list() : tail_(head_)
    {
    }
    void Insert(int val)
    {
        tail_->next_ = new Node(val);
        tail_ = tail_->next_;
    }
    ~list()
    {
        while (head_ != nullptr)
        {
            auto cur = head_;
            head_ = head_->next_;
            delete cur;
        }
    }
    void print()
    {
        auto cur = head_->next_;
        while (cur != nullptr)
        {
            cout << cur->val << " ";
            cur = cur->next_;
        }
        cout << endl;
    }
};

bool delete_min(list *l)
{
    if (l->head_->next_ == nullptr)
    {
        return false;
    }

    Node *min = l->head_->next_;
    auto cur = l->head_->next_;
    auto pre = l->head_;
    auto delpre = pre;
    int Min = INT_MAX;
    while (cur != nullptr)
    {
        if (cur->val < Min)
        {
            delpre = pre;
            min = cur;
            Min = min->val;
        }
        pre = cur;
        cur = cur->next_;
    }
    delpre->next_ = min->next_;
    delete min;
    return true;
}

int main()
{
    list l_1;
    l_1.Insert(2);
    l_1.Insert(4);
    l_1.Insert(5);
    l_1.Insert(3);
    l_1.Insert(1);
    l_1.Insert(0);
    l_1.Insert(2);
    l_1.Insert(6);
    l_1.Insert(7);
    l_1.Insert(5);
    l_1.print();
    delete_min(&l_1);
    l_1.print();
    return 0;
}