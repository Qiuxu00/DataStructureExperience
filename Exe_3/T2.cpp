#include <iostream>
#include <stack>
using namespace std;

template <class T>
class myQueue
{
    stack<T> st_in;
    stack<T> st_out;

public:
    bool push(T val)
    {
        st_in.push(val);
        return true;
    }
    T pop()
    {
        if (empty())
        {
            cerr << "the quene is empty!" << endl;
            throw;
        }
        if (st_out.empty())
        {
            while (!st_in.empty())
            {
                st_out.push(st_in.top());
                st_in.pop();
            }
        }
        T Top = st_out.top();
        st_out.pop();
        return Top;
    }
    T peek()
    {
        if (empty())
        {
            cerr << "the quene is empty!" << endl;
            throw;
        }
        if (st_out.empty())
        {
            while (!st_in.empty())
            {
                st_out.push(st_in.top());
                st_in.pop();
            }
        }
        return st_out.top();
    }
    bool empty()
    {
        return (st_in.empty() && st_out.empty());
    }
};

int main()
{
    myQueue<int> q1;
    for (int i = 0; i < 10; i++)
    {
        q1.push(i / 2);
    }
    // 0 0 1 1 2 2 3 3 4 4
    for (int i = 0; i < 5; i++)
    {
        cout << q1.pop() << " ";
    }
    // 2 3 3 4 4
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        q1.push(i * 2);
    }
    // 2 3 3 4 4 0 2 4 6 8
    for (int i = 0; i < 7; i++)
    {
        cout << q1.pop() << " ";
    }
    // 4 6 8
    cout << endl;
    cout << q1.peek() << endl;
    return 0;
}