#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fns(vector<int> &nums, int target)
{

    vector<vector<int>> result;
    if (nums.size() < 4)
    {
        return result;
    }
    sort(nums.begin(), nums.end());
    for (int first = 0; first < nums.size() - 3; first++)
    {
        if (first > 0 && nums[first] == nums[first - 1])
        {
            continue;
        }
        for (int second = first + 1; second < nums.size() - 2; second++)
        {
            if (second > first + 1 && nums[second] == nums[second - 1])
            {
                continue;
            }
            int L = second + 1;
            int R = nums.size() - 1;
            while (L != R)
            {
                if (L > second + 1 && nums[L] == nums[L - 1])
                {
                    L++;
                    continue;
                }
                if (R < nums.size() - 1 && nums[R] == nums[R + 1])
                {
                    R--;
                    continue;
                }
                long long int temp = (long long)nums[first] + nums[second] + nums[L] + nums[R];
                if (temp < target)
                {
                    L++;
                }
                else if (temp > target)
                {
                    R--;
                }
                else
                {
                    result.push_back({nums[first], nums[second], nums[L], nums[R]});
                    R--;
                    L++;
                }
            }
        }
    }
    return result;
}

int main()
{
    vector<int> vec = {1, 0, -1, 2, -2, 0};
    for (auto i : fns(vec, 0))
    {
        for (int ii : i)
        {
            cout << ii << " " << endl;
        }
    }

    return 0;
}