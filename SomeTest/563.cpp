#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

class mh
{
public:
    vector<int> heap;
    int n;
    mh(int capacity) : n(0)
    {
        heap.resize(capacity + 1);
    }
    void insert(int x)
    {
        int i = ++n;
        if (i == 1)
        {
            heap[1] = x;
            return;
        }
        vector<int> path;
        for (int curr = i; curr >= 1; curr /= 2)
        {
            path.push_back(curr);
        } // 得到的是从脚到头的路径数组
        int low = 1, high = path.size() - 1;
        int cur = 0; // 默认插入在脚,cur指插入位置
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (heap[path[mid]] < x)
            {
                cur = mid; // x 比当前祖先大，继续往更高层找
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        // 移动让位
        for (int j = 0; j < cur; ++j)
        {
            heap[path[j]] = heap[path[j + 1]];
        }

        heap[path[cur]] = x;
    }
};
int main()
{
    srand(time(NULL));
    mh H(10);
    for (int i = 0; i < 6; i++)
    {
        H.insert(rand() % 10);
    }
    for (int i : H.heap)
    {
        cout << i << " ";
    }
    cout << endl;
    int k = 3;
    cout << "插入的是: " << k << endl;
    H.insert(k);
    cout << "Final: " << endl;
    for (int i : H.heap)
    {
        cout << i << " ";
    }

    return 0;
}