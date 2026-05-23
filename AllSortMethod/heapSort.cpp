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

/**
 * 堆调整函数 (Heap Adjust / Sift Down)
 * 作用：将以 i 为根节点的子树调整为大顶堆
 * 前提：假设 i 的左右子树已经是堆了
 * * @param arr  待排序数组
 * @param i    当前需要调整的节点索引 (current root)
 * @param len  当前堆的大小 (heap size)，超过这个范围的元素不参与调整
 */

void heapAdjust(std::vector<int> &arr, int i, int len)
{
    int temp = arr[i]; // 1. 先把当前根节点的值取出来（挖坑），避免后续反复交换

    // 2. 开始向下遍历子节点
    // k = 2*i + 1 是 i 的左孩子
    for (int k = 2 * i + 1; k < len; k = k * 2 + 1)
    {

        // 如果右孩子存在，且右孩子比左孩子大，k 指向右孩子
        if (k + 1 < len && arr[k] < arr[k + 1])
        {
            k++;
        }

        // 3. 比较孩子节点和 temp (原本的根节点值)
        if (arr[k] > temp)
        {
            // 如果孩子比 temp 大，就把孩子的值上移到父节点（填坑）
            arr[i] = arr[k];

            // i 指针下移，指向刚才那个孩子的位置，因为它成了新的坑
            i = k;
        }
        else
        {
            // 如果孩子不比 temp 大，说明 temp 放在 i 位置是合法的
            // 不需要再往下找了，筛选结束
            break;
        }
    }

    // 4. 将最初取出的 temp 填入最终确定的位置
    arr[i] = temp;
}

// 堆排序主函数
void heapSort(std::vector<int> &arr)
{
    int n = arr.size();

    // ================= STEP 1: 建堆 =================
    // 从最后一个"非叶子节点"开始，自下而上、自右至左地进行调整
    // 最后一个非叶子节点索引是 n/2 - 1
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapAdjust(arr, i, n);
    }

    // 建堆完成，此时 arr[0] 是整个数组的最大值
    // std::cout << "建堆后状态: "; printVector(arr);

    // ================= STEP 2: 排序 =================
    // 不断将堆顶元素（最大值）与末尾元素交换，并将堆的大小减 1
    for (int i = n - 1; i > 0; --i)
    {

        // 1. 将堆顶元素（当前最大）交换到数组末尾
        // 这里的交换必须做，因为是把最大值"固定"到有序区
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 2. 交换后，堆顶结构被破坏了，需要重新调整
        // 注意：此时堆的大小变成了 i (因为索引 i 的元素已经排好了)
        // 我们只需要从 0 开始调整即可，因为左右子树依然是堆
        heapAdjust(arr, 0, i);
    }
}

int main()
{
    // 测试用例
    std::vector<int> data = {50, 10, 90, 30, 70, 40, 80, 60, 20};

    std::cout << "排序前: ";
    printVector(data);

    // 执行堆排序
    heapSort(data);

    std::cout << "排序后: ";
    printVector(data);

    return 0;
}