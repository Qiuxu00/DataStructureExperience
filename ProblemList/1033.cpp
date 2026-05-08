#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct work
{
    int ddl;
    int val;
};

void solve(vector<int> &res)
{
    int N;
    // 1. 检查输入是否成功，避免 N 是垃圾值
    if (!(cin >> N))
        return;

    // 如果 N 过大，这里可能会抛出异常，实际应用中需根据题目范围判断
    vector<work> W(N);
    for (int i = 0; i < N; ++i)
    {
        if (!(cin >> W[i].ddl >> W[i].val))
            break;
    }

    // 2. 使用 const 引用，这是更安全的做法
    sort(W.begin(), W.end(), [](const work &w1, const work &w2)
         {
             return w1.val < w2.val; // 确保是严格小于
         });

    // 提示：res 在这里被传入但没被使用，可能也是你逻辑上的遗漏
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    if (!(cin >> n))
        return 0;

    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    return 0;
}