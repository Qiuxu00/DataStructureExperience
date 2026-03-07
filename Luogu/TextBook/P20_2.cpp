#include <bits/stdc++.h>
using namespace std;

pair<int, int> merge(pair<int, int> &left_, pair<int, int> &right_)
{
    int mx = max({left_.first, left_.second, right_.first, right_.second});
    int sec_mx = mx;
    for (int x : {left_.first, left_.second, right_.first, right_.second})
    {
        if (x < mx)
        {
            if (sec_mx == mx || x > sec_mx)
            {
                sec_mx = x;
            }
        }
    }

    return {sec_mx, mx};
}

pair<int, int> rec(vector<int> &vec, int L, int R)
{
    if (L == R)
    {
        return {vec[L], vec[R]};
    }
    int mid = L + (R - L) / 2;
    auto left_ = rec(vec, L, mid);
    auto right_ = rec(vec, mid + 1, R);
    return merge(left_, right_);
}

void inlet(vector<int> &vec)
{
    auto res = rec(vec, 0, vec.size() - 1);
    cout << res.first << " " << res.second << endl;
}

int main()
{
    vector<int> vec = {1};
    inlet(vec);
    return 0;
}