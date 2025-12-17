#include <iostream>
#include <vector>

// 打印向量的辅助函数
void printVector(const std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// 折半插入排序函数
void binaryInsertionSort(std::vector<int> &arr)
{
    int n = arr.size();

    // 从第二个元素开始遍历
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i]; // 待插入的元素
        int low = 0;
        int high = i - 1; // 在已排序区间 [0...i-1] 中查找

        // 1. 使用二分查找寻找插入位置
        // 目标是找到第一个大于 key 的位置，该位置即为 low
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] > key)
            {
                // 如果中间值比 key 大，说明插入点在左半边
                high = mid - 1;
            }
            else
            {
                // 如果中间值比 key 小或相等，说明插入点在右半边
                // 注意：这里处理相等的情况让 low = mid + 1，保证了排序的稳定性
                low = mid + 1;
            }
        }

        // 此时，low 就是 key 应该插入的位置

        // 2. 移动元素
        // 将从 low 到 i-1 的所有元素向后移动一位
        for (int j = i - 1; j >= low; --j)
        {
            arr[j + 1] = arr[j];
        }

        // 3. 插入元素
        arr[low] = key;
    }
}

int main()
{
    // 测试用例
    std::vector<int> data = {32, 15, 2, 99, 15, 0, 4, 7};

    std::cout << "排序前: ";
    printVector(data);

    // 执行折半插入排序
    binaryInsertionSort(data);

    std::cout << "排序后: ";
    printVector(data);

    return 0;
}