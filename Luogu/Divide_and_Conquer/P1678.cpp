#include <bits/stdc++.h>
using namespace std;

long long search_r(vector<int> &vec, long long target, int L, int R)
{
    if (R < 0)
        R = 0;
    if (R >= vec.size())
        R = vec.size() - 1;
    if (L >= R)
    {
        if (vec[R] == target)
        {
            return 0;
        }
        else
        {
            long long q_0 = __INT_MAX__;
            long long q_1 = abs(vec[R] - target);
            long long q_2 = __INT_MAX__;
            if (R - 1 >= 0)
            {
                q_0 = abs(vec[R - 1] - target);
            }
            if (R + 1 < vec.size())
            {
                q_2 = abs(vec[R + 1] - target);
            }
            return min({q_0, q_1, q_2});
        }
    }

    int mid = L + (R - L) / 2;
    if (vec[mid] == target)
    {
        return 0;
    }
    else if (vec[mid] > target)
    {
        return search_r(vec, target, L, mid - 1);
    }
    else
    {
        return search_r(vec, target, mid + 1, R);
    }
}

long long search_in(vector<int> &vec, int target)
{
    return search_r(vec, target, 0, vec.size() - 1);
}

int main()
{
    // 算法竞赛必备的 IO 加速，防止读取大量数据时 TLE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    // 读取学校数量 m 和学生数量 n
    if (!(cin >> m >> n))
        return 0;

    vector<int> schools(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> schools[i];
    }

    // 二分搜索的前提：必须保证数组是有序的
    sort(schools.begin(), schools.end());

    long long total_diff = 0; // 记录所有学生的不满意度总和，防止爆 int

    for (int i = 0; i < n; ++i)
    {
        long long student_score;
        cin >> student_score;

        // 核心调用：累加当前学生的最优差值
        total_diff += search_in(schools, student_score);
    }

    // 输出最终结果
    cout << total_diff << "\n";
    return 0;
}