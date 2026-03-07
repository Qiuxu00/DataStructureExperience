#include <bits/stdc++.h>
using namespace std;

int ky(int n, vector<int> &weight)
{
    int min_ = __INT_MAX__;
    for (int i = 0; i < weight.size() - 1; i++)
    {
        for (int ii = i + 1; ii < weight.size(); ii++)
        {
            int result = 0;
            vector<int> temp(weight);
            temp[i] = 0;
            temp[ii] = 0;
            sort(temp.begin(), temp.end());
            for (int cur = 2; cur < 2 * n - 1; cur += 2)
            {
                result += abs(temp[cur] - temp[cur + 1]);
            }
            if (result < min_)
            {
                min_ = result;
            }
        }
    }
    return min_;
}

int main()
{
    return 0;
}