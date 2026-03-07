#include <bits/stdc++.h>
using namespace std;
// vector中：0（min），1（max），4（差值），2（差值大于0时候的左界），3（差值大于0时候的右界）
vector<int> merge(vector<int> &left_, vector<int> &right_)
{

    if (left_[4] >= 0 && right_[4] >= 0)
    {
        if (right_[1] - left_[0] > left_[4] && right_[1] - left_[0] > right_[4])
        {
            return {min(left_[0], right_[0]), max(left_[1], right_[1]), left_[0], right_[1], right_[1] - left_[0]};
        }
        else if (right_[4] > left_[4])
        {
            return {min(left_[0], right_[0]), max(left_[1], right_[1]), right_[2], right_[3], right_[4]};
        }
        else
        {
            return {min(left_[0], right_[0]), max(left_[1], right_[1]), left_[2], left_[3], left_[4]};
        }
    }
    return {-1, -1, -1, -1, -1};
}

vector<int> rec(vector<int> &vec, int L, int R)
{
    if (L == R)
    {
        return {vec[L], vec[R], vec[L], vec[L], 0};
    }
    int mid = L + (R - L) / 2;
    auto left_ = rec(vec, L, mid);
    auto right_ = rec(vec, mid + 1, R);
    return merge(left_, right_);
}

void inlet(vector<int> &vec)
{
    if (vec.empty())
    {
        cout << "Nan" << endl;
        return;
    }
    auto res = rec(vec, 0, vec.size() - 1);
    if (res[4] > 0)
    {
        cout << res[2] << ' ' << res[3] << endl;
    }
    else
    {
        cout << "Nan" << endl;
    }
}

int main()
{
    vector<int> vec = {7, 5, 4, 3, 2, 6, 7, 8, 6, 2, 1};
    inlet(vec);
    return 0;
}