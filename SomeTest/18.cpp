#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    Node(char V = -1) : val(V)
    {
    }
    char val;
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
    void Insert(char val)
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
            if (cur != nullptr)
            {
                delete cur;
            }
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
    Node *find_val(char a)
    {
        auto cur = head_->next_;
        while (cur != nullptr)
        {
            if (cur->val == a)
            {
                return cur;
            }
            cur = cur->next_;
        }
        return nullptr;
    }
};

void max_postfix(list *l_1, list *l_2)
{
    int length_1 = 0;
    int length_2 = 0;
    auto cur_1 = l_1->head_->next_;
    auto cur_2 = l_2->head_->next_;

    for (; cur_1 != nullptr || cur_2 != nullptr;)
    {
        if (cur_1 != nullptr)
        {
            length_1++;
            cur_1 = cur_1->next_;
        }
        if (cur_2 != nullptr)
        {
            length_2++;
            cur_2 = cur_2->next_;
        }
    }
    cur_1 = l_1->head_->next_;
    cur_2 = l_2->head_->next_;

    int bias = abs(length_1 - length_2);
    if (length_1 > length_2)
    {
        for (int i = 0; i < bias; i++)
        {
            cur_1 = cur_1->next_;
        }
    }
    else
    {
        for (int i = 0; i < bias; i++)
        {
            cur_2 = cur_2->next_;
        }
    }
    while (cur_1 != nullptr && cur_2 != nullptr && cur_1 != cur_2)
    {
        cur_1 = cur_1->next_;
        cur_2 = cur_2->next_;
    }
    cout << "The first letter of the postfix is " << cur_1->val << " " << endl;
}

int main()
{
    list l_1;
    list l_2;
    l_1.Insert('n');
    l_1.Insert('i');
    l_1.Insert('h');
    l_1.Insert('a');
    l_1.Insert('o');
    l_2.Insert('w');
    l_2.Insert('o');
    l_2.tail_->next_ = l_1.find_val('h');
    l_1.print();
    l_2.print();
    max_postfix(&l_1, &l_2);
    return 0;
}