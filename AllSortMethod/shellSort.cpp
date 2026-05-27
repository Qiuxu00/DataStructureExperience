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

// 希尔排序函数
void shellSort(std::vector<int> &arr)
{
    int n = arr.size();

    // 1. 初始化增量 gap，通常初始为 n/2
    // 每次循环后 gap 减半，直到 gap = 0 时停止
    for (int gap = n / 2; gap > 0; gap /= 2)
    {

        // 2. 对每个 gap 分组进行直接插入排序
        // 注意：这里我们不是一个组排完再排下一个组，
        // 而是从第 gap 个元素开始，依次对所属组进行插入操作
        // 这样写代码更紧凑，效果是一样的
        for (int i = gap; i < n; ++i)
        {

            int temp = arr[i]; // 当前待插入的元素
            int j;

            // 3. 在当前组内进行插入排序逻辑
            // 比较对象是当前位置减去 gap (j - gap)
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap]; // 如果前面的大，就往后挪
            }

            // 4. 找到位置，填入
            arr[j] = temp;
        }
        // 可选：打印每一轮 gap 排序后的状态，方便观察
        // std::cout << "Gap=" << gap << ": ";
        // printVector(arr);
    }
}

int main()
{
    // 测试用例
    std::vector<int> data = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};

    std::cout << "排序前: ";
    printVector(data);

    // 执行希尔排序
    shellSort(data);

    std::cout << "排序后: ";
    printVector(data);

    return 0;
}