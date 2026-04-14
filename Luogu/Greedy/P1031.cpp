#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    // 实际题目建议用 cin 读入 N
    int N;
    cin >> N;
    vector<int> heap(N);
    for (int &i : heap)
    {
        cin >> i;
    }
    int n = heap.size();

    // 1. 计算平均值
    int sum = accumulate(heap.begin(), heap.end(), 0);
    int target = sum / n;

    int result = 0;

    // 2. 贪心处理：从左往右，把差值全部扔给下一堆
    for (int i = 0; i < n - 1; i++)
    {
        if (heap[i] != target)
        {
            // 将当前堆与目标的差值“传递”给下一堆
            heap[i + 1] += heap[i] - target;
            // 只要不相等，就肯定需要一次移动
            result++;
        }
    }

    cout << result << endl;
    return 0;
}