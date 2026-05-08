#include <bits/stdc++.h>
using namespace std;

void solve(vector<bool> &res)
{
    int N, X;
    cin >> N >> X;
    vector<int> nums(N);
    for (auto &i : nums)
    {
        cin >> i;
    }
    sort(nums.begin(), nums.end());
    int ptr_1 = 0;
    int ptr_2 = N - 1;
    while (ptr_1 < ptr_2)
    {
        if (nums[ptr_1] + nums[ptr_2] > X)
        {
            ptr_2--;
        }
        else if (nums[ptr_1] + nums[ptr_2] < X)
        {
            ptr_1++;
        }
        else
        {
            res.push_back(true);
            return;
        }
    }
    res.push_back(false);
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<bool> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (auto i : res)
    {
        if (i)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}