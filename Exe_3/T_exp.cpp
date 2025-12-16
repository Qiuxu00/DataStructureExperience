#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

template <class T>
void find(T num1[], int n, T num2[], int m)
{
    stack<T> result;
    unordered_map<T, T> map1;
    for (int i = 0; i < m; i++)
    {
        map1[num2[i]] = -1; // 设置默认值
        if (result.empty())
        {
            result.push(num2[i]);
        }
        while (!result.empty() && num2[i] > result.top())
        {
            map1[result.top()] = num2[i]; // 一直找到停下
            result.pop();
        }
        result.push(num2[i]);       // 要在上面全都比完才入栈
        if (num2[i] < result.top()) // 小了就直接放进去吧，无影响，后面有大的会由上面的代码一路比下去
        {
            result.push(num2[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << map1[num1[i]] << " ";
    }
    cout << endl;
}

int main()
{
    /*
     * 测试用例格式:
     * cout << "--- Case X ---" << endl;
     * int num1_X[] = { ... };
     * int num2_X[] = { ... };
     * // 预期答案: [ ... ]
     * find(num1_X, sizeof(num1_X)/sizeof(int), num2_X, sizeof(num2_X)/sizeof(int));
     */

    // --- Case 1: 题目示例 (常规情况) ---
    // 预期答案: [-1, 3, -1]
    int num1_1[] = {4, 1, 2};
    int num2_1[] = {1, 3, 4, 2};
    find(num1_1, 3, num2_1, 4);

    // --- Case 2: nums2 严格递减 (全为 -1) ---
    // 预期答案: [-1, -1]
    int num1_2[] = {5, 4};
    int num2_2[] = {5, 4, 3, 2, 1};
    find(num1_2, 2, num2_2, 5);

    // --- Case 3: nums2 严格递增 (全有答案) ---
    // 预期答案: [2, 3, 4]
    int num1_3[] = {1, 2, 3};
    int num2_3[] = {1, 2, 3, 4, 5};
    find(num1_3, 3, num2_3, 5);

    // --- Case 4: 包含 nums2 的最后一个元素 ---
    // 预期答案: [-1, 5]
    int num1_4[] = {4, 2};
    int num2_4[] = {1, 2, 5, 4};
    find(num1_4, 2, num2_4, 4);

    // --- Case 5: 空的 nums1 ---
    // 预期答案: []
    int num1_5[] = {};
    int num2_5[] = {1, 2, 3};
    find(num1_5, 0, num2_5, 3);
    return 0;
}