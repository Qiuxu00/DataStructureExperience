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

// 合并函数 (Merge)
// 作用：将两个有序区间 [left, mid] 和 [mid+1, right] 合并为一个有序区间
void merge(std::vector<int> &arr, int left, int mid, int right)
{
    // 1. 创建一个临时数组来存放合并后的结果
    // 长度为当前处理的总元素个数
    std::vector<int> temp(right - left + 1);

    int i = left;    // 左半区间的起点
    int j = mid + 1; // 右半区间的起点
    int k = 0;       // 临时数组的索引

    // 2. 比较并合并
    // 只要左右两边都还有元素，就PK一下，小的先放入 temp
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            // 注意：这里用 <= 保证了算法的稳定性
            // 如果左边的数等于右边的数，优先取左边的（因为左边原本就在前面）
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    // 3. 处理剩余元素
    // 如果左边还有剩，全部抄过去
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    // 如果右边还有剩，全部抄过去
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    // 4. 将排序好的临时数组搬回原数组
    // 注意原数组是从 left 开始的
    for (int p = 0; p < temp.size(); ++p)
    {
        arr[left + p] = temp[p];
    }
}

// 归并排序递归函数
void mergeSort(std::vector<int> &arr, int left, int right)
{
    // 递归终止条件：当区间只有一个元素或不存在时，不需要排序
    if (left < right)
    {
        // 取中间位置，防止 (left+right) 溢出的标准写法
        int mid = left + (right - left) / 2;

        // 递归处理左半边
        mergeSort(arr, left, mid);

        // 递归处理右半边
        mergeSort(arr, mid + 1, right);

        // 合并两个有序的半边
        merge(arr, left, mid, right);
    }
}

int main()
{
    // 测试用例
    std::vector<int> data = {8, 4, 5, 7, 1, 3, 6, 2};

    std::cout << "排序前: ";
    printVector(data);

    // 调用归并排序，初始范围是整个数组
    if (!data.empty())
    {
        mergeSort(data, 0, data.size() - 1);
    }

    std::cout << "排序后: ";
    printVector(data);

    return 0;
}