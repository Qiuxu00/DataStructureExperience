#include <bits/stdc++.h>
using namespace std;
int main()
{
    int L, N;
    if (!(cin >> L >> N))
        return 0;

    // 特判：如果桥上没有士兵，直接输出 0 0
    if (N == 0)
    {
        cout << "0 0" << endl;
        return 0;
    }

    vector<int> pos(N);
    for (int i = 0; i < N; i++)
    {
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());
    int min_ = L + 1 - pos[0];
    for (int i = 0; i < pos.size() - 1; i++)
    {
        min_ = min(min_, max(pos[i], L + 1 - pos[i + 1]));
    }
    min_ = min(min_, pos[pos.size() - 1]);
    int max_ = max((L + 1 - pos[0]), pos[pos.size() - 1]);
    cout << min_ << " " << max_ << endl;
    return 0;
}