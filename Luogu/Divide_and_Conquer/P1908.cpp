#include <bits/stdc++.h>
using namespace std;

int result = 0;
void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> vec(right - left + 1); // 数组大小加一
    int l_start = left;
    int r_start = mid + 1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (r_start <= right && l_start <= mid && arr[r_start] < arr[l_start]) // 填数逻辑要弄清
        {
            result += (mid - l_start + 1);
            vec[i] = arr[r_start];
            r_start++;
        }
        else if (l_start <= mid)
        {
            vec[i] = arr[l_start];
            l_start++;
        }
        else if (r_start <= right)
        {
            vec[i] = arr[r_start];
            r_start++;
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        arr[left + i] = vec[i];
    }
}

int mergeSort(std::vector<int> &arr, int left, int right)
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
    return result;
}

int main()
{
    vector<int> vec = {5, 4, 2, 6, 3, 1};
    cout << mergeSort(vec, 0, vec.size() - 1) << endl;
    return 0;
}