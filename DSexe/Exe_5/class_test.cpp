#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
using namespace std;
// 3 5 2 6 5 10 11 13 12 15
// 寻找一个元素使得左边的都小于它，右边的都大于它
int Choose(int arr[], int size)
{
    if (size <= 1)
    {
        return NAN;
    }
    vector<int> right_min(size);
    vector<int> left_max(size);
    int right_MIN = INT_MAX;
    for (int i = size - 1; i >= 0; i--)
    {
        right_min[i] = min(right_MIN, arr[i]);
        right_MIN = right_min[i];
    }
    int left_MAX = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        left_max[i] = max(left_MAX, arr[i]);
        left_MAX = left_max[i];
        if (i == 0)
        {
            if (arr[i] < right_min[i + 1])
            {
                return arr[0];
            }
        }
        else if (i == size - 1)
        {
            if (arr[i] > left_max[i - 1])
            {
                return arr[i];
            }
        }
        else if (arr[i] > left_max[i - 1] && arr[i] < right_min[i + 1])
        {
            return arr[i];
        }
    }
    return NAN;
}
int main()
{
    int arr[] = {3, 5, 2, 6, 5, 10, 11, 13, 12, 15};
    if (Choose(arr, 10) != NAN)
    {
        cout << Choose(arr, 10) << endl;
    }
    else
    {
        cout << "NAN" << endl;
    }
    return 0;
}