#include <bits/stdc++.h>
using namespace std;

int dn(vector<int> &vec)
{
    int nums = 0;
    int temp = 0;
    sort(vec.begin(), vec.end());
    for (int i : vec)
    {
        if (i != temp)
        {
            temp = i;
            nums++;
        }
    }
    return nums;
}

int main()
{
    vector<int> vec = {2, 3, 3, 2, 2};
    cout << dn(vec) << endl;
    return 0;
}