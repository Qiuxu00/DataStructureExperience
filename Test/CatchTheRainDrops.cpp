#include <vector>
#include <iostream>
#include <algorithm> // 必须包含这个头文件来使用 max_element

using namespace std;

int ctrd(vector<int> &vec)
{
    if (vec.empty())
        return 0;

    // --- 步骤1：找到最高点 ---
    // 就像分水岭一样，把问题切成两半，互不干扰
    int max_idx = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > vec[max_idx])
            max_idx = i;
    }

    int result = 0;

    // --- 步骤2：左边扫到最高点 ---
    int ptr_1 = 0;
    // 找到第一个非0起点
    while (ptr_1 < max_idx && vec[ptr_1] == 0)
        ptr_1++;

    int ptr_2 = ptr_1 + 1;
    int ocu = 0;

    while (ptr_2 <= max_idx) // 注意：只扫到 max_idx
    {
        while (ptr_2 < max_idx && vec[ptr_2] < vec[ptr_1])
        {
            ocu += vec[ptr_2];
            ptr_2++;
        }

        // 因为 max_idx 是最高的，所以只要到了 max_idx，或者遇到了更高的墙，就结算
        if (ptr_2 <= max_idx && vec[ptr_2] >= vec[ptr_1])
        {
            result += (vec[ptr_1] * (ptr_2 - ptr_1 - 1) - ocu);
            ptr_1 = ptr_2;
            ptr_2++;
            ocu = 0;
        }
    }

    // --- 步骤3：右边扫到最高点 ---
    ptr_1 = vec.size() - 1;
    // 找到右边第一个非0起点
    while (ptr_1 > max_idx && vec[ptr_1] == 0)
        ptr_1--;

    ptr_2 = ptr_1 - 1;
    ocu = 0;

    while (ptr_2 >= max_idx) // 注意：只扫到 max_idx
    {
        while (ptr_2 > max_idx && vec[ptr_2] < vec[ptr_1])
        {
            ocu += vec[ptr_2];
            ptr_2--;
        }

        // 同样，遇到了 max_idx 或更高的墙就结算
        if (ptr_2 >= max_idx && vec[ptr_2] >= vec[ptr_1])
        {
            result += (vec[ptr_1] * (ptr_1 - ptr_2 - 1) - ocu);
            ptr_1 = ptr_2;
            ptr_2--;
            ocu = 0;
        }
    }

    return result;
}

int main()
{
    vector<int> vec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // 预期输出: 6
    // 原错误代码可能输出: 4 或更小
    cout << ctrd(vec) << endl;
    return 0;
}