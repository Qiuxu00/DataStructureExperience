#include <bits/stdc++.h>
using namespace std;

void solve(vector<bool> &res)
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int &i : nums)
    {
        cin >> i;
    }
    sort(nums.begin(), nums.end());
    int ptr_1 = 0;
    int ptr_2 = n - 1;
    while (ptr_1 < ptr_2)
    {
        int temp = nums[ptr_1] + nums[ptr_2];
        if (temp == k)
        {
            res.push_back(true);
            return;
        }
        else if (temp > k)
        {
            ptr_2--;
        }
        else
        {
            ptr_1++;
        }
    }
    res.push_back(false);
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
    for (bool i : res)
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