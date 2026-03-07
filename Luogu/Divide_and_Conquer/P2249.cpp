#include <bits/stdc++.h>
using namespace std;
int search_r(vector<int> &vec, int target, int L, int R)
{
    if (L == R)
    {
        if (vec[L] == target)
        {
            return L + 1;
        }
        else
        {
            return -1;
        }
    }
    if (L > R)
    {
        return -1;
    }
    int mid = L + (R - L) / 2;
    if (vec[mid] >= target)
    {
        return search_r(vec, target, L, mid);
    }
    else
    {
        return search_r(vec, target, mid + 1, R);
    }
}

vector<int> search(vector<int> &vec, queue<int> &q)
{
    vector<int> result;
    while (!q.empty())
    {
        result.push_back(search_r(vec, q.front(), 0, vec.size() - 1));
        q.pop();
    }
    return result;
}

int main()
{
    // 【IO修改点】：嵌入极致 Fast IO 核心
    static char buf[1000000], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++)

    auto read = [&]()
    {
        int x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
            ch = getchar();
        while (ch >= '0' && ch <= '9')
        {
            x = x * 10 + ch - '0';
            ch = getchar();
        }
        return x;
    };

    // 动态读取规模
    int n = read();
    int m = read();

    // 构造原数组
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        vec[i] = read();
    }

    // 构造查询队列
    queue<int> tar;
    for (int i = 0; i < m; i++)
    {
        tar.push(read());
    }

    // 调用你的 search 函数并输出
    vector<int> res = search(vec, tar);
    for (int i : res)
    {
        printf("%d ", i);
    }

    return 0;
}