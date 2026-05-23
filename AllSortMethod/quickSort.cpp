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

// 分区函数 (Partition)
// 核心逻辑：选取 low 位置的元素作为基准 pivot，
// 然后通过移动 high 和 low 指针，将比 pivot 小的放到左边，大的放到右边
int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[low]; // 1. 选基准，挖出第一个坑，此时 arr[low] 可以被覆盖

    while (low < high)
    {
        // 2. 从右向左找一个小于 pivot 的数
        while (low < high && arr[high] >= pivot)
        {
            high--;
        }
        // 找到了小于 pivot 的数，填入左边的坑 arr[low]
        if (low < high)
        {
            arr[low] = arr[high];
            low++; // low 指针右移，准备找下一个
        }

        // 3. 从左向右找一个大于 pivot 的数
        while (low < high && arr[low] <= pivot)
        {
            low++;
        }
        // 找到了大于 pivot 的数，填入右边的坑 arr[high]
        // (刚才 arr[high] 的值已经搬走了，所以这里是安全的)
        if (low < high)
        {
            arr[high] = arr[low];
            high--; // high 指针左移
        }
    }
    // 4. 当 low == high 时，循环结束
    // 此时的位置就是基准值应该在的正确位置
    arr[low] = pivot;
    return low; // 返回基准值的索引
}

// 快速排序递归函数
void quickSortRecursive(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // 获取基准值的位置
        int pivotPos = partition(arr, low, high);

        // 递归处理基准值左边的子数组
        quickSortRecursive(arr, low, pivotPos - 1);

        // 递归处理基准值右边的子数组
        quickSortRecursive(arr, pivotPos + 1, high);
    }
}

// 封装后的入口函数，方便调用
void quickSort(std::vector<int> &arr)
{
    if (arr.empty())
        return;
    quickSortRecursive(arr, 0, arr.size() - 1);
}

int main()
{
    // 测试用例
    std::vector<int> data = {49, 38, 65, 97, 76, 13, 27, 49};

    std::cout << "排序前: ";
    printVector(data);

    // 执行快速排序
    quickSort(data);

    std::cout << "排序后: ";
    printVector(data);

    return 0;
}