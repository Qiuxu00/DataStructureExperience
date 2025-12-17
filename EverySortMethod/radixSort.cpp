#include <iostream>
#include <vector>
#include <queue> // 必须使用 queue 来实现"链表"桶的 FIFO 特性

// 打印向量的辅助函数
void printVector(const std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// 获取数组中的最大值，用于确定循环次数
int getMaxVal(const std::vector<int> &arr)
{
    int maxVal = arr[0];
    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// 基数排序函数
void radixSort(std::vector<int> &arr)
{
    if (arr.empty())
        return;

    // 1. 获取最大值，确定最大位数
    int maxVal = getMaxVal(arr);

    // 2. 定义10个桶，每个桶是一个队列（链表）
    // buckets[0] 存放某一位是 0 的数，buckets[1] 存放某一位是 1 的数...
    std::vector<std::queue<int>> buckets(10);

    // 3. 循环处理每一位
    // exp 是指数：1 (个位), 10 (十位), 100 (百位)...
    // 当 exp 超过 maxVal 时循环结束
    for (long long exp = 1; maxVal / exp > 0; exp *= 10)
    {

        // --- 分发过程 (Distribute) ---
        for (size_t i = 0; i < arr.size(); ++i)
        {
            // 取出当前位上的数字 (0-9)
            // 例如：123 / 1 % 10 = 3 (个位)
            //       123 / 10 % 10 = 2 (十位)
            int digit = (arr[i] / exp) % 10;

            // 放入对应的桶中
            buckets[digit].push(arr[i]);
        }

        // --- 收集过程 (Collect) ---
        // 将10个桶里的数据依次倒回原数组
        int index = 0;
        for (int i = 0; i < 10; ++i)
        {
            // 只要桶不为空，就一直往外拿
            while (!buckets[i].empty())
            {
                arr[index++] = buckets[i].front(); // 取队头
                buckets[i].pop();                  // 弹出
            }
        }

        // 调试打印：每一轮排序后的状态
        // std::cout << "Exp=" << exp << ": ";
        // printVector(arr);
    }
}

int main()
{
    // 测试用例
    // 注意：标准基数排序通常处理非负整数
    std::vector<int> data = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "排序前: ";
    printVector(data);

    // 执行基数排序
    radixSort(data);

    std::cout << "排序后: ";
    printVector(data);

    return 0;
}