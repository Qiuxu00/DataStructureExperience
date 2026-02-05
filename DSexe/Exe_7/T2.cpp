#include <iostream>
#include <vector>
using namespace std;

class heap
{
public:
    vector<int> heap_;
    int size = 0;

    void sift_up()
    {
        int i = size - 1;
        while (i > 0)
        {
            if (heap_[i] > heap_[(i + 1) / 2 - 1])
            {
                swap(heap_[i], heap_[(i + 1) / 2 - 1]);
                i = (i + 1) / 2 - 1;
            }
            else
            {
                return;
            }
        }
    }
    void sift_down()
    {
        int i = 0;
        while (i * 2 + 1 < size)
        {
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            int largest = left;
            if (right < size && heap_[right] > heap_[left])
            {
                largest = right;
            }
            if (heap_[largest] > heap_[i])
            {
                swap(heap_[i], heap_[largest]);
                i = largest;
            }
            else
            {
                break;
            }
        }
    }
    void insert(int val)
    {
        heap_.push_back(val);
        size++;
        sift_up();
    }
};
void heap_sort(vector<int> &vec)
{
    heap h1;
    for (auto i : vec)
    {
        h1.insert(i);
    }
    for (int i = 0; i < h1.heap_.size() - 1; i++)
    {
        swap(h1.heap_[0], h1.heap_[h1.size - 1]);
        h1.size--;
        h1.sift_down();
    }
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = h1.heap_[i];
    }
}
// 你好
int main()
{
    vector<int> test = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    for (auto i : test)
    {
        cout << i << " ";
    }
    cout << endl
         << "快排之后: " << endl;
    heap_sort(test);
    for (auto i : test)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}