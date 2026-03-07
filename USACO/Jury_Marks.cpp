#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/**
 * 问题：C. Jury Marks
 * 复杂度：O(k^2 log k) 或 O(k * n log k)
 */

int main()
{
    // 优化输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    if (!(cin >> k >> n))
        return 0;

    vector<int> a(k);
    vector<int> pre(k);
    int current_sum = 0;

    // 1. 读取评分并计算前缀和
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
        current_sum += a[i];
        pre[i] = current_sum;
    }

    // 2. 读取记忆中的分数
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    // 将前缀和排序，方便后续使用二分查找验证得分是否存在
    sort(pre.begin(), pre.end());
    // 去重前缀和可以稍微提高一点效率，但不是必须
    pre.erase(unique(pre.begin(), pre.end()), pre.end());

    // 3. 寻找所有可能的初始分数 S
    // 我们知道 b[0] 一定等于某个 S + pre[i]，所以 S = b[0] - 原本的前缀和
    // 注意：这里需要重新计算一下未去重前的前缀和产生的 S，或者直接用原始数据
    set<int> candidate_S;
    // 我们用一个临时的累加来找回原始的每一个 pre_i
    int temp_sum = 0;
    for (int i = 0; i < k; ++i)
    {
        temp_sum += a[i];
        candidate_S.insert(b[0] - temp_sum);
    }

    int valid_count = 0;

    // 4. 验证每一个候选的初始分数 S
    for (int s : candidate_S)
    {
        bool all_found = true;
        for (int i = 0; i < n; ++i)
        {
            // 我们要找是否有某个 pre[j] 使得 s + pre[j] == b[i]
            // 即查找 pre 数组中是否存在值 (b[i] - s)
            if (!binary_search(pre.begin(), pre.end(), b[i] - s))
            {
                all_found = false;
                break;
            }
        }
        if (all_found)
        {
            valid_count++;
        }
    }

    // 5. 输出结果
    cout << valid_count << endl;

    return 0;
}