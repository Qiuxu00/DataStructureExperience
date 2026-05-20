#include <bits/stdc++.h>
using namespace std;

void rec(vector<int> &nums, int l, int r, int times = 1)
{
    if (l >= r)
    {
        return;
    }
    int pivot = nums[l];
    int left = l;
    int right = r;
    while (left < right)
    {
        while (left < right && nums[right] >= pivot)
        {
            right--;
        }
        if (left < right && nums[right] < pivot)
        {
            swap(nums[left], nums[right]);
        }
        while (left < right && nums[left] <= pivot)
        {
            left++;
        }
        if (left < right && nums[left] > pivot)
        {
            swap(nums[left], nums[right]);
        }
    }
    if (times == 2)
    {
        return;
    }
    rec(nums, l, left - 1, times + 1);
    rec(nums, right + 1, r, times + 1);

    return;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &i : nums)
    {
        cin >> i;
    }
    rec(nums, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        solve();
    }
    return 0;
}