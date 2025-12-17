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

// 冒泡排序函数
void bubbleSort(std::vector<int> &arr)
{
    int n = arr.size();

    // 外层循环：控制比较的轮数
    // 每一轮结束后，最大的那个元素会被"冒泡"到数组的最后面
    for (int i = 0; i < n - 1; ++i)
    {

        bool swapped = false; // 优化标志位：记录本轮是否发生过交换

        // 内层循环：两两比较相邻元素
        // 范围是 [0, n - 1 - i]，因为最后面的 i 个元素已经排好序了
        for (int j = 0; j < n - 1 - i; ++j)
        {

            // 如果前一个比后一个大，就交换它们
            if (arr[j] > arr[j + 1])
            {
                // 手动交换，不依赖 std::swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true; // 标记发生了交换
            }
        }

        // 优化点：如果这一轮完全没有交换过，说明数组已经有序了
        // 直接跳出循环，节省时间
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    // 测试用例
    std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "排序前: ";
    printVector(data);

    // 执行冒泡排序
    bubbleSort(data);

    std::cout << "排序后: ";
    printVector(data);

    return 0;
}