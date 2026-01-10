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
        if (!this->head_->next_)
        {
            cout << "NULL LIST" << endl;
            return;
        }
        auto cur = head_->next_;
        while (cur != nullptr)
        {
            cout << cur->val << " ";
            cur = cur->next_;
        }
        cout << endl;
    }
};

list common_val(list *l_1, list *l_2)
{
    list result;
    if (l_1->head_->next_ == nullptr || l_2->head_->next_ == nullptr)
    {

        return result;
    }

    auto cur_1 = l_1->head_->next_;
    auto cur_2 = l_2->head_->next_;
    while (cur_1 != nullptr && cur_2 != nullptr)
    {
        if (cur_1->val < cur_2->val)
        {
            while (cur_1 != nullptr && cur_1->val < cur_2->val)
            {
                cur_1 = cur_1->next_;
            }
        }
        else if (cur_2->val < cur_1->val)
        {
            while (cur_2 != nullptr && cur_2->val < cur_1->val)
            {
                cur_2 = cur_2->next_;
            }
        }

        if (cur_1->val == cur_2->val)
        {
            result.Insert(cur_1->val);
            cur_1 = cur_1->next_;
            cur_2 = cur_2->next_;
        }
    }

    return result;
}

int main()
{
    list l_1;
    l_1.Insert(4);
    l_1.Insert(6);
    l_1.Insert(5);
    l_1.Insert(8);
    l_1.Insert(9);
    l_1.Insert(12);
    l_1.Insert(14);
    l_1.Insert(15);

    l_1.print();
    list l_2;
    l_2.Insert(0);
    l_2.Insert(1);
    l_2.Insert(3);
    l_2.Insert(5);
    l_2.Insert(6);
    l_2.Insert(8);
    l_2.Insert(12);
    l_2.Insert(14);
    l_2.print();
    common_val(&l_1, &l_2).print();

    return 0;
}