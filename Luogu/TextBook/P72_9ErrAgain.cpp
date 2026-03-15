#include <bits/stdc++.h>
using namespace std;

tuple<double, double, int> getnode(tuple<double, double, int> &p_1, tuple<double, double, int> &p_2)
{
    auto [l_x, l_y, l_num] = p_1;
    auto [r_x, r_y, r_num] = p_2;
    auto new_x = (l_num * l_x + r_num * r_x) / (double)(l_num + r_num);
    auto new_y = (l_num * l_y + r_num * r_y) / (double)(l_num + r_num);
    auto new_num = l_num + r_num;
    return {new_x, new_y, new_num};
}

tuple<double, double, int> rec(vector<pair<int, int>> &vec, int L, int R)
{
    if (L == R)
    {
        return {vec[L].first, vec[L].second, 1};
    }
    int mid = (L + R) / 2;
    auto left_ = rec(vec, L, mid);
    auto right_ = rec(vec, mid + 1, R);
    return getnode(left_, right_);
}

void inlet(vector<pair<int, int>> &vec)
{
    auto [x, y, n] = rec(vec, 0, vec.size() - 1);
    cout << "( " << x << " , " << y << " )" << endl;
}

int main()
{
    vector<pair<int, int>> vec = {{5, 12}, {1, 3}, {9, 8}, {4, 15}, {11, 2}};
    inlet(vec);
    return 0;
}