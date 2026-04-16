#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0
    vector<int> nums = {1, 2, 0, 1};
    vector<int> farthest(nums.size());
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        farthest[i] = (i + nums[i]) > nums.size() - 1 ? nums.size() - 1 : i + nums[i];
    }

    for (int start = 0; start < nums.size();)
    {
        int max_ = 0;
        int max_pos = -1;
        if (farthest[start] == nums.size() - 1)
        {
            result++;
            break;
        }
        for (int i = start + 1; i <= farthest[start]; i++)
        {
            if (farthest[i] > max_)
            {
                max_ = farthest[i];
                max_pos = i;
            }
        }
        start = max_pos;
        result++;
    }
    cout << result << endl;
    return 0;
}