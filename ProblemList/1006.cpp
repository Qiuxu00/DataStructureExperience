#include <bits/stdc++.h>
using namespace std;

void sift_down(vector<int> &nums, int pos)
{
    int smallest = pos;
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    if (left < nums.size() && nums[left] < nums[smallest])
    {
        smallest = left;
    }
    if (right < nums.size() && nums[right] < nums[smallest])
    {
        smallest = right;
    }
    if (smallest != pos)
    {
        swap(nums[pos], nums[smallest]);
        sift_down(nums, smallest);
    }
}

void solve(vector<vector<int>> &res)
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &i : nums)
    {
        cin >> i;
    }
    int last_p = (n / 2) - 1;
    for (int i = last_p; i >= 0; i--)
    {
        sift_down(nums, i);
    }
    res.push_back(nums);
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
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}