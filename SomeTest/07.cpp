#include <iostream>
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

void delete_same(list *l)
{
    if (l->head_->next_ == nullptr)
    {
        return;
    }
    auto pre = l->head_->next_;
    auto cur = l->head_->next_->next_;
    while (cur != nullptr)
    {
        if (pre->val == cur->val)
        {
            pre->next_ = cur->next_;
            delete cur;
            cur = pre->next_;
        }
        else
        {
            pre = pre->next_;
            cur = cur->next_;
        }
    }
}

int main()
{
    list l_1;
    l_1.Insert(2);
    l_1.Insert(2);
    l_1.print();
    delete_same(&l_1);
    l_1.print();
    return 0;
}