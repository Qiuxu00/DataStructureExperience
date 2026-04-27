#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int L, int R)
{
    vector<int> res;
    int mid = (L + R) / 2;
    int ptr_1 = L;
    int ptr_2 = mid + 1;
    while (ptr_1 <= mid && ptr_2 <= R)
    {
        if (nums[ptr_1] >= nums[ptr_2])
        {
            res.push_back(nums[ptr_2]);
            ptr_2++;
        }
        else
        {
            res.push_back(nums[ptr_1]);
            ptr_1++;
        }
    }
    if (ptr_1 <= mid)
    {
        while (ptr_1 <= mid)
        {
            res.push_back(nums[ptr_1]);
            ptr_1++;
        }
    }
    else if (ptr_2 <= R)
    {
        while (ptr_2 <= R)
        {
            res.push_back(nums[ptr_2]);
            ptr_2++;
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        nums[L + i] = res[i];
    }
}

void rec(vector<int> &vec, int L, int R, int times = 0)
{

    if (L == R)
    {
        return;
    }

    int mid = (L + R) / 2;
    rec(vec, L, mid, times + 1);
    rec(vec, mid + 1, R, times + 1);
    if (times >= 2)
    {
        merge(vec, L, R);
    }
}

void solve(vector<vector<int>> &res)
{
    int S;
    cin >> S;
    vector<int> nums(S);
    for (auto &i : nums)
    {
        cin >> i;
    }
    rec(nums, 0, nums.size() - 1);
    res.push_back(nums);
}

void test()
{
    vector<int> vec = {2, 3, 1, 2, 4};
    rec(vec, 0, vec.size() - 1);
    for (int i : vec)
    {
        cout << i;
    }
    cout << endl;
}

int main()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<vector<int>> vec;
    for (int i = 0; i < n; i++)
    {
        solve(vec);
    }
    for (auto v : vec)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}