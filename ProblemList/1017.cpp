#include <bits/stdc++.h>
using namespace std;

int result = 0;
void merge(vector<int> &nums, int L, int R)
{
    vector<int> temp;
    int mid = (L + R) / 2;
    int ptr_1 = L;
    int ptr_2 = mid + 1;
    while (ptr_1 <= mid && ptr_2 <= R)
    {
        if (nums[ptr_2] < nums[ptr_1])
        {
            temp.push_back(nums[ptr_2++]);
            result += (mid - ptr_1 + 1);
        }
        else
        {
            temp.push_back(nums[ptr_1++]);
        }
    }
    while (ptr_1 <= mid)
    {
        temp.push_back(nums[ptr_1++]);
    }
    while (ptr_2 <= R)
    {
        temp.push_back(nums[ptr_2++]);
    }
    for (int i = 0; i < temp.size(); i++)
    {
        nums[L + i] = temp[i];
    }
}

void rec(vector<int> &nums, int L, int R)
{
    if (L >= R)
    {
        return;
    }
    int mid = (L + R) / 2;
    rec(nums, L, mid);
    rec(nums, mid + 1, R);
    merge(nums, L, R);
}

void solve(vector<int> &res)
{
    int N;
    cin >> N;
    vector<int> nums(N);
    for (auto &i : nums)
    {
        cin >> i;
    }
    result = 0;
    rec(nums, 0, N - 1);
    res.push_back(result);
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