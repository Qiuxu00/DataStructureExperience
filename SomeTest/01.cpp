#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int val;
    Node *next_ = nullptr;
    Node(int x) : val(x) {}
    Node() {}
};

class List
{
public:
    Node *head_ = new Node(0);
    List() : tail_(head_)
    {
    }
    void insert(int val)
    {
        tail_->next_ = new Node(val);
        tail_ = tail_->next_;
    }
    void Print()
    {
        auto cur = head_->next_;
        while (cur != nullptr)
        {
            cout << cur->val << " ";
            cur = cur->next_;
        }
        cout << endl;
    }
    ~List()
    {
        while (head_ != nullptr)
        {
            auto cur = head_;
            head_ = head_->next_;
            delete cur;
        }
    }

private:
    Node *tail_ = nullptr;
};

bool is_circle(List *l)
{
    stack<int> result;
    auto cur = l->head_->next_;
    int length = 0;
    while (cur != nullptr)
    {
        length++;
        cur = cur->next_;
    }
    if (length == 1)
    {
        return true;
    }
    cur = l->head_->next_;
    int count = 0;
    while (cur != nullptr)
    {
        if (count <= length / 2 - 1)
        {
            result.push(cur->val);
        }
        if (count >= (length + 1) / 2)
        {
            if (cur->val != result.top())
            {
                return false;
            }
            result.pop();
        }
        count++;
        cur = cur->next_;
    }
    return true;
}

void test()
{
    List l_1;
    int arr[] = {2};
    for (int i = 0; i < 1; i++)
    {
        l_1.insert(arr[i]);
    }
    l_1.Print();
    cout << boolalpha << is_circle(&l_1) << endl;
}

int main()
{
    test();
    return 0;
}