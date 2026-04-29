#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int L, int R, int &Res)
{
    vector<int> temp;
    int mid = (L + R) / 2;
    int ptr_1 = L;
    int ptr_2 = mid + 1;
    while (ptr_1 <= mid && ptr_2 <= R)
    {
        if (nums[ptr_2] < nums[ptr_1])
        {
            temp.push_back(nums[ptr_2]);
            Res += (mid - ptr_1 + 1);
            ptr_2++;
        }
        else
        {
            temp.push_back(nums[ptr_1]);
            ptr_1++;
        }
    }
    while (ptr_1 <= mid)
    {
        temp.push_back(nums[ptr_1]);
        ptr_1++;
    }
    while (ptr_2 <= R)
    {
        temp.push_back(nums[ptr_2]);
        ptr_2++;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        nums[L + i] = temp[i];
    }
}

void rec(vector<int> &nums, int L, int R, int &Res)
{
    if (L == R)
    {
        return;
    }
    int mid = (L + R) / 2;
    rec(nums, L, mid, Res);
    rec(nums, mid + 1, R, Res);
    merge(nums, L, R, Res);
}

void solve(vector<int> &res)
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &i : nums)
    {
        cin >> i;
    }
    int Res = 0;
    rec(nums, 0, n - 1, Res);
    res.push_back(Res);
}

int main()
{
    int n;
    cin >> n;
    vector<int> res;
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