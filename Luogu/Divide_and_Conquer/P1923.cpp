#include <bits/stdc++.h>
using namespace std;
int rec(vector<int> &vec, int L, int R, int k)
{
    swap(vec[L], vec[L + rand() % (R - L + 1)]);
    if (L > R)
    {
        return -1;
    }
    int lt = L;
    int rt = R;
    int i = L + 1;
    int pivot = vec[L];
    while (i <= rt)
    {
        if (vec[i] < pivot)
        {
            swap(vec[lt], vec[i]);
            i++;
            lt++;
        }
        else if (vec[i] > pivot)
        {
            swap(vec[rt], vec[i]);
            rt--;
        }
        else
        {
            i++;
        }
    }
    if (lt > k)
    {
        return rec(vec, L, lt - 1, k);
    }
    else if (rt < k)
    {
        return rec(vec, rt + 1, R, k);
    }
    else
    {
        return vec[lt];
    }
}
int inlet(vector<int> &vec, int k)
{
    return rec(vec, 0, vec.size() - 1, k);
}

int main()
{
    // 【关键优化】：解除 cin/cout 与 C 标准库的同步，极限提升读写速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k))
        return 0;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    // 【关键优化】：不要使用 endl，endl 会强制刷新缓冲区导致变慢，改用 "\n"
    cout << inlet(vec, k) << "\n";
    return 0;
}