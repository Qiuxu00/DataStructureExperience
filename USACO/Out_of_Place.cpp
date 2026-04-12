#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums;
    int result = -1;
    bool smaller = true;
    int pos = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == 0)
        {
            if (nums[i] > nums[i + 1])
            {
                result = 0;
            }
        }
        else if (i < nums.size() - 1)
        {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            {
                smaller = false;
                pos = i;
                break;
            }
            else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])
            {
                smaller = true;
                pos = i;
                break;
            }
        }
        else if (i == nums.size() - 1)
        {
            if (nums[i] < nums[i - 1])
            {
                smaller = true;
                pos = i;
            }
        }
    }
    if (result == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        result = 0;
        if (smaller)
        {
        }
    }

    return 0;
}