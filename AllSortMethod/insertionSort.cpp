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

// 标准插入排序函数
// 参数使用引用传递，直接修改原数组
void insertionSort(std::vector<int> &arr)
{
    int n = arr.size();

    // 从第二个元素开始遍历（因为第一个元素默认是有序的）
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i]; // 当前需要插入的元素（基准值）
        int j = i - 1;    // 已排序部分的最后一个元素索引

        // 在已排序部分中从后往前扫描
        // 如果当前元素大于 key，则将其向后移动一位
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // 元素后移
            j--;                 // 继续向前比较
        }

        // 找到正确位置，插入 key
        // 此时 j 指向的是比 key 小的元素（或者 -1），所以插入位置是 j + 1
        arr[j + 1] = key;
    }
}

int main()
{
    // 测试用例
    std::vector<int> data = {12, 11, 13, 5, 6, 11, 9, 0};

    std::cout << "排序前: ";
    printVector(data);

    // 执行插入排序
    insertionSort(data);

    std::cout << "排序后: ";
    printVector(data);

    return 0;
}