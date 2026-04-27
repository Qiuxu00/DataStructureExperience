#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &res)
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (auto &i : num)
    {
        cin >> i;
    }
    int min_ = __INT_MAX__;
    int sec_min_ = __INT_MAX__;
    for (int i : num)
    {
        if (i <= min_)
        {
            sec_min_ = min_;
            min_ = i;
        }
        else if (i > min_ && i <= sec_min_)
        {
            sec_min_ = i;
        }
    }
    res.push_back(sec_min_);
}

int main()
{
    int n;
    vector<int> res;
    if (!(cin >> n))
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (int i : res)
    {
        cout << i << endl;
    }

    return 0;
}