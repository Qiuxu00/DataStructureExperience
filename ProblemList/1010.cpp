#include <bits/stdc++.h>
using namespace std;

pair<int, int> rec(vector<int> &nums, int L, int R, int father, int X)
{
    if (L > R)
    {
        return {0, father};
    }
    if (L == R && nums[L] == X)
    {
        return {1, father};
    }
    int mid = (L + R) / 2;
    if (nums[mid] == X)
    {
        return {1, father};
    }
    father = nums[mid];
    if (nums[mid] > X)
    {
        return rec(nums, L, mid - 1, father, X);
    }
    else
    {
        return rec(nums, mid + 1, R, father, X);
    }
}

void solve(vector<vector<int>> &res)
{
    int N, X;
    cin >> N >> X;
    vector<int> nums(N);
    for (int &i : nums)
    {
        cin >> i;
    }
    auto p = rec(nums, 0, N - 1, nums[(N - 1) / 2], X);
    vector<int> Res;
    Res.push_back(p.first);
    Res.push_back(p.second);
    res.push_back(Res);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (auto v : res)
    {
        if (!v[0])
        {
            cout << "not found, father is " << v[1] << endl;
        }
        else
        {
            cout << "success, father is " << v[1] << endl;
        }
    }
    return 0;
}