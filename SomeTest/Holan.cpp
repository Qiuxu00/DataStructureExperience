#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void RWB(vector<int> &v)
{
    int r(0), g(1), b(0);
    while (g < v.size())
    {
        if (v[g] == 0)
        {
            while (v[r] == 0)
            {
                r++;
            }
            swap(v[r], v[g]);
            r++;
        }
        g++;
    }
    g = r + 1;
    while (g < v.size())
    {
        if (v[g] == 1)
        {
            while (v[r] == 1)
            {
                r++;
            }
            swap(v[r], v[g]);
            r++;
        }
        g++;
    }
}

void sortColors(std::vector<int> &nums)
{
    int low = 0;                // 0 的右边界
    int mid = 0;                // 当前处理的元素
    int high = nums.size() - 1; // 2 的左边界

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            // 将 0 换到前面，low 和 mid 同步右移
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            // 1 已经在中间区域，直接跳过
            mid++;
        }
        else
        { // nums[mid] == 2
            // 将 2 换到后面，由于换回来的数未知，mid 不动
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> v = {0, 1, 2, 0, 0, 1, 2, 0, 0, 2, 2, 0, 1};
    RWB(v);
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}