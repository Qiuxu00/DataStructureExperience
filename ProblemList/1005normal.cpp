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
    rec(nums, l, left - 1, times + 1);
    rec(nums, right + 1, r, times + 1);
    if (times == 2)
    {
        for (int i : nums)
        {
            cout << i << ' ';
        }
        cout << endl;
    }

    return;
}
void test()
{
    vector<int> nums = {6, 3, 7, 8, 5, 1, 4, 2, 4, 9, 10};
    rec(nums, 0, 10);
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
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        solve();
    }
}