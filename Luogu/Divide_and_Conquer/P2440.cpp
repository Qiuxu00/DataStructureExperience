#include <bits/stdc++.h>
using namespace std;

long long counter(vector<int> &vec, int find_l)
{
    long long result = 0;
    for (int i : vec)
    {
        result += (i / find_l);
    }
    return result;
}

int rec(vector<int> &vec, int length_min, int length_max, int k) // 保证这里面的两个最值都是可以取到的
{

    if (length_max == 1 && counter(vec, 1) < k)
    {
        return 0;
    }
    if (abs(length_max - length_min) <= 1)
    {
        return (counter(vec, length_max) >= k ? length_max : length_min);
    }
    int mid = (length_max + length_min) / 2 + 1;
    if (counter(vec, mid) >= k)
    {
        return rec(vec, mid, length_max, k);
    }
    else
    {
        return rec(vec, length_min, mid - 1, k);
    }
}

long long inlet(vector<int> &vec, long long k)
{
    if (counter(vec, 1) < k)
    {
        return 0;
    }
    int max_h = 0;
    for (int i : vec)
    {
        if (i > max_h)
        {
            max_h = i;
        }
    }

    return rec(vec, 1, max_h, k);
}

int main()
{
    // --- 快速 I/O 核心代码 ---
    ios::sync_with_stdio(false); // 解除 C++ 输入输出流与 C 标准库的绑定
    cin.tie(nullptr);            // 解除 cin 与 cout 的绑定

    int n;
    long long k;

    // 洛谷标准读取：先读 N(木头数量) 和 K(需要切的段数)
    if (cin >> n >> k)
    {
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i]; // 循环读取每根木头的长度
        }

        // 快速 I/O 的另一个细节：用 "\n" 替代 endl。
        // 因为 endl 会强制刷新缓冲区，导致输出变慢。
        cout << inlet(vec, k) << "\n";
    }
    return 0;
}