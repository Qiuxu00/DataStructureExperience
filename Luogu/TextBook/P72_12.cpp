#include <bits/stdc++.h>
using namespace std;
// min.max
pair<int, int> rec(vector<int> &vec, int L, int R)
{
    if (L == R)
    {
        return {vec[L], vec[R]};
    }
    if (L + 1 == R) // It makes when R-L==1,then compare directly and not allow to devide into two condition
    {
        if (vec[L] < vec[R])
        {
            return {vec[L], vec[R]};
        }
        else
        {
            return {vec[R], vec[L]};
        }
    }
    int mid = (L + R) / 2;
    auto left_ = rec(vec, L, mid);
    auto right_ = rec(vec, mid + 1, R);
    int cur_max = max(left_.second, right_.second);
    int cur_min = min(left_.first, right_.first);
    return {cur_min, cur_max};
}

void inlet(vector<int> &vec)
{
    auto res = rec(vec, 0, vec.size() - 1);
    cout << "min: " << res.first << endl
         << "max: " << res.second << endl;
}

int main()
{
    vector<int> vec = {84, 12, 45, 93, 2, 67, 31, 58, 19, 76};
    inlet(vec);
    return 0;
}