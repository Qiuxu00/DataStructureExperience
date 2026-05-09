#include <bits/stdc++.h>

using namespace std;

struct work
{
    int ddl;
    int val;
};
bool comp(work &w1, work &w2)
{
    return w1.val > w2.val;
}
function<bool(work &, work &)> Compare = comp;

void solve(vector<long long> &res)
{
    int N;
    if (!(cin >> N))
        return;

    vector<work> W(N);
    int max_ddl = 0;
    for (int i = 0; i < N; ++i)
    {
        if (!(cin >> W[i].ddl >> W[i].val))
            break;
        if (W[i].ddl > max_ddl)
        {
            max_ddl = W[i].ddl;
        }
    }
    sort(W.begin(), W.end(), [](const work &w1, const work &w2)
         { return w1.ddl < w2.ddl; });                                // 现在W是按照ddl从小到大
    priority_queue<work, vector<work>, decltype(Compare)> q(Compare); // q是最小堆，比较的是val
    int ptr = 0;
    while (ptr < N)
    {
        if (q.size() + 1 > W[ptr].ddl)
        {
            if (q.top().val < W[ptr].val)
            {
                q.pop();
                q.push(W[ptr++]);
            }
            else
            {
                ptr++;
            }
        }
        else
        {
            q.push(W[ptr++]);
        }
    }
    long long result = 0;
    while (!q.empty())
    {
        result += q.top().val;
        q.pop();
    }
    res.push_back(result);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    if (!(cin >> n))
        return 0;

    vector<long long> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (long long i : res)
    {
        cout << i << endl;
    }
    return 0;
}