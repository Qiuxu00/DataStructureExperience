#include <iostream>
using namespace std;

template <class T>
class Quene
{
    int rear = 0;
    int front = 0;
    T *q = nullptr;
    int capacity;

public:
    Quene(int size) : capacity(size + 1)
    {
        q = new T[capacity];
    }
    ~Quene()
    {
        delete[] q;
    }
    bool isEmpty()
    {
        return (front == rear);
    }
    bool isFul()
    {
        return ((rear + 1) % capacity == front);
    }
    void push(T val)
    {
        if (isFul())
        {
            cerr << "is ful" << endl;
            throw;
        }
        q[rear] = val;
        rear = (rear + 1) % capacity;
    }
    T pop()
    {
        if (isEmpty())
        {
            cerr << "is empty" << endl;
            throw;
        }
        T val = q[front];

        front = (front + 1) % capacity;
        return val;
    }
    T getFront()
    {
        return q[front];
    }
    Quene<T> *split()
    {

        Quene<T> *q2 = new Quene<T>(capacity / 2 + 1);
        int rear_ = rear;
        int front_ = front;
        for (int i = 0; (front_ + i) % capacity != rear_; i++)
        {
            if (i % 2 == 0)
            {
                this->push(this->pop());
            }
            else
            {
                q2->push(this->pop());
            }
        }

        return q2;
    }
};

int main()
{
    return 0;
}
